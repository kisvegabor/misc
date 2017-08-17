/**
 * @file font.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "../../misc_conf.h"
#if USE_TEXT != 0

#include "text.h"
#include "../math/math_base.h"

/*********************
 *      DEFINES
 *********************/
#define TXT_NO_BREAK_FOUND  UINT16_MAX

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static bool txt_is_break_char(char letter);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Get size of a text
 * @param size_res pointer to a 'point_t' variable to store the result
 * @param text pointer to a text
 * @param font pinter to font of the text
 * @param letter_space letter space of the text
 * @param line_space line space of the text
 * @param flags settings for the text from 'txt_flag_t' enum
 * @param max_width max with of the text (break the lines to fit this size) Set CORD_MAX to avoid line breaks
 */
void txt_get_size(point_t * size_res, const char * text, const font_t * font,
                    cord_t letter_space, cord_t line_space, cord_t max_width, txt_flag_t flag)
{
    size_res->x = 0;
    size_res->y = 0;

    if(text == NULL) return;
    if(font == NULL) return;

    if(flag & TXT_FLAG_EXPAND) max_width = CORD_MAX;

    uint32_t line_start = 0;
    uint32_t new_line_start = 0;
    cord_t act_line_length;
    uint8_t letter_height = font_get_height(font) >> FONT_ANTIALIAS;

    /*Calc. the height and longest line*/
    while (text[line_start] != '\0') {
        new_line_start += txt_get_next_line(&text[line_start], font, letter_space, max_width, flag);
        size_res->y += letter_height ;
        size_res->y += line_space;

        /*Calculate the the longest line*/
        act_line_length = txt_get_width(&text[line_start], new_line_start - line_start,
                                       font, letter_space, flag);

        size_res->x = MATH_MAX(act_line_length, size_res->x);
        line_start = new_line_start;
    }

    if(line_start != 0 && (text[line_start - 1] == '\n' || text[line_start - 1] == '\r')) {
        size_res->y += letter_height + line_space;
    }

    /*Correction with the last line space or set the height manually if the text is empty*/
    if(size_res->y == 0) size_res->y = letter_height;
    else size_res->y -= line_space;

}

/**
 * Get the next line of text. Check line length and break chars too.
 * @param txt a '\0' terminated string
 * @param font pointer to a font
 * @param letter_space letter space
 * @param max_width max with of the text (break the lines to fit this size) Set CORD_MAX to avoid line breaks
 * @param flags settings for the text from 'txt_flag_type' enum
 * @return the index of the first char of the new line
 */
uint16_t txt_get_next_line(const char * txt, const font_t * font,
                           cord_t letter_space, cord_t max_width, txt_flag_t flag)
{
    if(txt == NULL) return 0;
    if(font == NULL) return 0;

    if(flag & TXT_FLAG_EXPAND) max_width = CORD_MAX;

    uint32_t i = 0;
    cord_t act_l = 0;
    uint16_t last_break = TXT_NO_BREAK_FOUND;
    txt_cmd_state_t cmd_state = TXT_CMD_STATE_WAIT;
    
    while(txt[i] != '\0') {

        /*Handle the recolor command*/
        if((flag & TXT_FLAG_RECOLOR) != 0) {
            if(txt_is_cmd(&cmd_state, txt[i]) != false) {
                i++;    /*Skip the letter is it is part of a command*/
                continue;
            }
        }
        /*Check for new line chars*/
        if((flag & TXT_FLAG_NO_BREAK) == 0 && (txt[i] == '\n' || txt[i] == '\r')) {
            /*Handle \n\r and \r\n as well*/
            if(txt[i] == '\n' && txt[i + 1] == '\r') {
                i++;
            } else if(txt[i] == '\r' && txt[i + 1] == '\n') {
                i++;
            }
            return i+1;    /*Return with the first letter of the next line*/

        } else { /*Check the actual length*/
            act_l += font_get_width(font, txt[i]) >> FONT_ANTIALIAS;

            /*If the txt is too long then finish, this is the line end*/
            if(act_l > max_width) {
                /*If already a break character is found, then break there*/
                if(last_break != TXT_NO_BREAK_FOUND && txt_is_break_char(txt[i]) == false) {
                    i = last_break;
                }

                while(txt[i] == ' ') i++;

                /* Do not let to return without doing nothing.
                 * Find at least one character */
                if(i == 0) i++;

                return i;
            }
            /*If this char still can fit to this line then check if 
             * txt can be broken here later */
            else if(txt_is_break_char(txt[i])) {
                last_break = i;
                last_break++;/*Go to the next char, the break char stays in this line*/
            }
        }
        
        act_l += letter_space;
        i++;
    }
    
    return i;
}

/**
 * Give the length of a text with a given font
 * @param txt a '\0' terminate string
 * @param char_num number of characters in 'txt'
 * @param font pointer to a font
 * @param letter_space letter space
 * @param flags settings for the text from 'txt_flag_t' enum
 * @return length of a char_num long text
 */
cord_t txt_get_width(const char * txt, uint16_t char_num, 
                      const font_t * font, cord_t letter_space, txt_flag_t flag)
{
    if(txt == NULL) return 0;
    if(font == NULL) return 0;

    uint16_t i;
    cord_t len = 0;
    txt_cmd_state_t cmd_state = TXT_CMD_STATE_WAIT;
    
    if(char_num != 0) {
        for(i = 0; i < char_num; i++) {
            if((flag & TXT_FLAG_RECOLOR) != 0) {
                if(txt_is_cmd(&cmd_state, txt[i]) != false) {
                    continue;
                }
            }
            len += font_get_width(font, txt[i]) >> FONT_ANTIALIAS;
            len += letter_space;
        }
        
        /*Trim closing spaces */
        for(i = char_num - 1; i > 0; i--) {
            if(txt[i] == ' ') {
                len -= font_get_width(font, txt[i]) >> FONT_ANTIALIAS;
                len -= letter_space;
            } else {
                break;
            }
        }
    }
    
    return len;
}

/**
 * Check next character in a string and decide if the character is part of the command or not
 * @param state pointer to a txt_cmd_state_t variable which stores the current state of command processing
 *             (Initied. to TXT_CMD_STATE_WAIT )
 * @param c the current character
 * @return true: the character is part of a command and should not be written,
 *         false: the character should be written
 */
bool txt_is_cmd(txt_cmd_state_t * state, char c)
{
    bool ret = false;

    if(c == TXT_RECOLOR_CMD) {
       if(*state == TXT_CMD_STATE_WAIT) { /*Start char*/
           *state = TXT_CMD_STATE_PAR;
           ret = true;
       } else if(*state == TXT_CMD_STATE_PAR) { /*Other start char in parameter is escaped cmd. char */
           *state = TXT_CMD_STATE_WAIT;
       }else if(*state == TXT_CMD_STATE_IN) { /*Command end */
           *state = TXT_CMD_STATE_WAIT;
           ret = true;
       }
   }

   /*Skip the color parameter and wait the space after it*/
   if(*state == TXT_CMD_STATE_PAR) {
       if(c == ' ') {
           *state = TXT_CMD_STATE_IN; /*After the parameter the text is in the command*/
       }
       ret = true;
   }

   return ret;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Test if char is break char or not (a text can broken here or not)
 * @param letter a letter
 * @return false: 'letter' is not break char
 */
static bool txt_is_break_char(char letter)
{
    uint8_t i;
    bool ret = false;
    
    /*Compare the letter to TXT_BREAK_CHARS*/
    for(i = 0; TXT_BREAK_CHARS[i] != '\0'; i++) {
        if(letter == TXT_BREAK_CHARS[i]) {
            ret = true; /*If match then it is break char*/
            break;
        }
    }
    
    return ret;
}

#endif /*USE_TEXT*/
