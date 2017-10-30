#include "misc_conf.h"
#if  USE_FONT_SYMBOL_25_FEEDBACK != 0
#include <stdint.h>
#include "misc/gfx/font.h"

/*Store the image of the letters (glyph) */
static const uint8_t symbol_25_feedback_bitmap[] = 
{
    // ASCII: 57408, char width: 11
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....
    0x00, 0x60,  // ---------OO.....
    0x00, 0xe0,  // --------OOO.....
    0x01, 0xe0,  // -------OOOO.....
    0x03, 0xe0,  // ------OOOOO.....
    0x07, 0xe0,  // -----OOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0xff, 0xe0,  // OOOOOOOOOOO.....
    0x07, 0xe0,  // -----OOOOOO.....
    0x03, 0xe0,  // ------OOOOO.....
    0x01, 0xe0,  // -------OOOO.....
    0x00, 0xe0,  // --------OOO.....
    0x00, 0x60,  // ---------OO.....
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....
    0x00, 0x00,  // -----------.....

    // ASCII: 57409, char width: 16
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------
    0x00, 0x60,  // ---------OO-----
    0x00, 0xe0,  // --------OOO-----
    0x01, 0xe0,  // -------OOOO-----
    0x03, 0xe0,  // ------OOOOO-----
    0x07, 0xe0,  // -----OOOOOO-----
    0xff, 0xe4,  // OOOOOOOOOOO--O--
    0xff, 0xe6,  // OOOOOOOOOOO--OO-
    0xff, 0xe3,  // OOOOOOOOOOO---OO
    0xff, 0xe3,  // OOOOOOOOOOO---OO
    0xff, 0xe3,  // OOOOOOOOOOO---OO
    0xff, 0xe6,  // OOOOOOOOOOO--OO-
    0xff, 0xe4,  // OOOOOOOOOOO--O--
    0x07, 0xe0,  // -----OOOOOO-----
    0x03, 0xe0,  // ------OOOOO-----
    0x01, 0xe0,  // -------OOOO-----
    0x00, 0xe0,  // --------OOO-----
    0x00, 0x60,  // ---------OO-----
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------
    0x00, 0x00,  // ----------------

    // ASCII: 57410, char width: 23
    0x00, 0x00, 0x00,  // -----------------------.
    0x00, 0x00, 0x00,  // -----------------------.
    0x00, 0x00, 0x80,  // ----------------O------.
    0x00, 0x00, 0xe0,  // ----------------OOO----.
    0x00, 0x60, 0x70,  // ---------OO------OOO---.
    0x00, 0xe0, 0x38,  // --------OOO-------OOO--.
    0x01, 0xe3, 0x98,  // -------OOOO---OOO--OO--.
    0x03, 0xe1, 0xcc,  // ------OOOOO----OOO--OO-.
    0x7f, 0xe0, 0xec,  // -OOOOOOOOOO-----OOO-OO-.
    0xff, 0xee, 0x66,  // OOOOOOOOOOO-OOO--OO--OO.
    0xff, 0xe7, 0x36,  // OOOOOOOOOOO--OOO--OO-OO.
    0xff, 0xe3, 0x36,  // OOOOOOOOOOO---OO--OO-OO.
    0xff, 0xe3, 0x36,  // OOOOOOOOOOO---OO--OO-OO.
    0xff, 0xe7, 0x36,  // OOOOOOOOOOO--OOO--OO-OO.
    0xff, 0xee, 0x66,  // OOOOOOOOOOO-OOO--OO--OO.
    0x7f, 0xe0, 0x6c,  // -OOOOOOOOOO------OO-OO-.
    0x07, 0xe1, 0xcc,  // -----OOOOOO----OOO--OO-.
    0x03, 0xe3, 0x9c,  // ------OOOOO---OOO--OOO-.
    0x01, 0xe3, 0x38,  // -------OOOO---OO--OOO--.
    0x00, 0xe0, 0x70,  // --------OOO------OOO---.
    0x00, 0x00, 0xe0,  // ----------------OOO----.
    0x00, 0x00, 0xc0,  // ----------------OO-----.
    0x00, 0x00, 0x00,  // -----------------------.
    0x00, 0x00, 0x00,  // -----------------------.
    0x00, 0x00, 0x00,  // -----------------------.

    // ASCII: 57411, char width: 25
    0x00, 0x1c, 0x00, 0x00,  // -----------OOO-----------.......
    0x00, 0x1c, 0x00, 0x00,  // -----------OOO-----------.......
    0x00, 0x3e, 0x00, 0x00,  // ----------OOOOO----------.......
    0x00, 0x7f, 0x00, 0x00,  // ---------OOOOOOO---------.......
    0x00, 0x7f, 0x00, 0x00,  // ---------OOOOOOO---------.......
    0x00, 0xff, 0x80, 0x00,  // --------OOOOOOOOO--------.......
    0x00, 0xff, 0x80, 0x00,  // --------OOOOOOOOO--------.......
    0x01, 0xe3, 0xc0, 0x00,  // -------OOOO---OOOO-------.......
    0x01, 0xe3, 0xc0, 0x00,  // -------OOOO---OOOO-------.......
    0x03, 0xe3, 0xe0, 0x00,  // ------OOOOO---OOOOO------.......
    0x03, 0xe3, 0xe0, 0x00,  // ------OOOOO---OOOOO------.......
    0x07, 0xe3, 0xf0, 0x00,  // -----OOOOOO---OOOOOO-----.......
    0x0f, 0xe3, 0xf8, 0x00,  // ----OOOOOOO---OOOOOOO----.......
    0x0f, 0xe3, 0xf8, 0x00,  // ----OOOOOOO---OOOOOOO----.......
    0x1f, 0xff, 0xfc, 0x00,  // ---OOOOOOOOOOOOOOOOOOO---.......
    0x1f, 0xff, 0xfc, 0x00,  // ---OOOOOOOOOOOOOOOOOOO---.......
    0x3f, 0xe3, 0xfe, 0x00,  // --OOOOOOOOO---OOOOOOOOO--.......
    0x3f, 0xe3, 0xfe, 0x00,  // --OOOOOOOOO---OOOOOOOOO--.......
    0x7f, 0xe3, 0xff, 0x00,  // -OOOOOOOOOO---OOOOOOOOOO-.......
    0x7f, 0xff, 0xff, 0x00,  // -OOOOOOOOOOOOOOOOOOOOOOO-.......
    0xff, 0xff, 0xff, 0x80,  // OOOOOOOOOOOOOOOOOOOOOOOOO.......
    0xff, 0xff, 0xff, 0x80,  // OOOOOOOOOOOOOOOOOOOOOOOOO.......
    0x7f, 0xff, 0xff, 0x00,  // -OOOOOOOOOOOOOOOOOOOOOOO-.......
    0x00, 0x00, 0x00, 0x00,  // -------------------------.......
    0x00, 0x00, 0x00, 0x00,  // -------------------------.......

    // ASCII: 57412, char width: 20
    0x00, 0x00, 0x00,  // --------------------....
    0x10, 0x00, 0x00,  // ---O----------------....
    0x78, 0x00, 0x00,  // -OOOO---------------....
    0x7c, 0x00, 0x00,  // -OOOOO--------------....
    0xfc, 0x00, 0x00,  // OOOOOO--------------....
    0xfe, 0x00, 0x00,  // OOOOOOO-------------....
    0xfe, 0x00, 0x00,  // OOOOOOO-------------....
    0xfc, 0x00, 0x00,  // OOOOOO--------------....
    0xf8, 0x00, 0x00,  // OOOOO---------------....
    0x78, 0x00, 0x00,  // -OOOO---------------....
    0x78, 0x00, 0x00,  // -OOOO---------------....
    0x3c, 0x00, 0x00,  // --OOOO--------------....
    0x3e, 0x00, 0x00,  // --OOOOO-------------....
    0x1f, 0x00, 0x00,  // ---OOOOO------------....
    0x0f, 0x83, 0x00,  // ----OOOOO-----OO----....
    0x07, 0xc7, 0xc0,  // -----OOOOO---OOOOO--....
    0x03, 0xff, 0xe0,  // ------OOOOOOOOOOOOO-....
    0x01, 0xff, 0xf0,  // -------OOOOOOOOOOOOO....
    0x00, 0xff, 0xe0,  // --------OOOOOOOOOOO-....
    0x00, 0x3f, 0xe0,  // ----------OOOOOOOOO-....
    0x00, 0x0f, 0x80,  // ------------OOOOO---....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....

    // ASCII: 57413, char width: 13
    0x00, 0x00,  // -------------...
    0x1f, 0x80,  // ---OOOOOO----...
    0x1f, 0x00,  // ---OOOOO-----...
    0x3f, 0x00,  // --OOOOOO-----...
    0x3f, 0x00,  // --OOOOOO-----...
    0x3e, 0x00,  // --OOOOO------...
    0x3e, 0x00,  // --OOOOO------...
    0x7e, 0x70,  // -OOOOOO--OOO-...
    0x7f, 0xf0,  // -OOOOOOOOOOO-...
    0x7f, 0xf0,  // -OOOOOOOOOOO-...
    0x7f, 0xe0,  // -OOOOOOOOOO--...
    0xff, 0xe0,  // OOOOOOOOOOO--...
    0xff, 0xc0,  // OOOOOOOOOO---...
    0x83, 0xc0,  // O-----OOOO---...
    0x03, 0x80,  // ------OOO----...
    0x03, 0x80,  // ------OOO----...
    0x07, 0x00,  // -----OOO-----...
    0x07, 0x00,  // -----OOO-----...
    0x06, 0x00,  // -----OO------...
    0x06, 0x00,  // -----OO------...
    0x0e, 0x00,  // ----OOO------...
    0x0c, 0x00,  // ----OO-------...
    0x0c, 0x00,  // ----OO-------...
    0x08, 0x00,  // ----O--------...
    0x00, 0x00,  // -------------...

    // ASCII: 57414, char width: 25
    0x00, 0x1c, 0x00, 0x00,  // -----------OOO-----------.......
    0x00, 0x1c, 0x00, 0x00,  // -----------OOO-----------.......
    0x00, 0x7f, 0x00, 0x00,  // ---------OOOOOOO---------.......
    0x00, 0xff, 0x80, 0x00,  // --------OOOOOOOOO--------.......
    0x01, 0xff, 0xc0, 0x00,  // -------OOOOOOOOOOO-------.......
    0x03, 0xff, 0xe0, 0x00,  // ------OOOOOOOOOOOOO------.......
    0x03, 0xff, 0xe0, 0x00,  // ------OOOOOOOOOOOOO------.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x07, 0xff, 0xf0, 0x00,  // -----OOOOOOOOOOOOOOO-----.......
    0x0f, 0xff, 0xf8, 0x00,  // ----OOOOOOOOOOOOOOOOO----.......
    0x0f, 0xff, 0xf8, 0x00,  // ----OOOOOOOOOOOOOOOOO----.......
    0x1f, 0xff, 0xfc, 0x00,  // ---OOOOOOOOOOOOOOOOOOO---.......
    0x1f, 0xff, 0xfc, 0x00,  // ---OOOOOOOOOOOOOOOOOOO---.......
    0x3f, 0xff, 0xfe, 0x00,  // --OOOOOOOOOOOOOOOOOOOOO--.......
    0x7f, 0xff, 0xff, 0x00,  // -OOOOOOOOOOOOOOOOOOOOOOO-.......
    0x7f, 0xff, 0xff, 0x00,  // -OOOOOOOOOOOOOOOOOOOOOOO-.......
    0x00, 0xff, 0x80, 0x00,  // --------OOOOOOOOO--------.......
    0x00, 0x7f, 0x00, 0x00,  // ---------OOOOOOO---------.......
    0x00, 0x3e, 0x00, 0x00,  // ----------OOOOO----------.......
    0x00, 0x1c, 0x00, 0x00,  // -----------OOO-----------.......

    // ASCII: 57415, char width: 20
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x20,  // ------------------O-....
    0x00, 0x00, 0xf0,  // ----------------OOOO....
    0x00, 0x03, 0xe0,  // --------------OOOOO-....
    0x00, 0x0f, 0xe0,  // ------------OOOOOOO-....
    0x00, 0x3f, 0xc0,  // ----------OOOOOOOO--....
    0x00, 0xff, 0xc0,  // --------OOOOOOOOOO--....
    0x03, 0xff, 0x80,  // ------OOOOOOOOOOO---....
    0x0f, 0xff, 0x80,  // ----OOOOOOOOOOOOO---....
    0x3f, 0xff, 0x00,  // --OOOOOOOOOOOOOO----....
    0xff, 0xff, 0x00,  // OOOOOOOOOOOOOOOO----....
    0xff, 0xfe, 0x00,  // OOOOOOOOOOOOOOO-----....
    0x00, 0x7e, 0x00,  // ---------OOOOOO-----....
    0x00, 0x7c, 0x00,  // ---------OOOOO------....
    0x00, 0x7c, 0x00,  // ---------OOOOO------....
    0x00, 0x78, 0x00,  // ---------OOOO-------....
    0x00, 0x78, 0x00,  // ---------OOOO-------....
    0x00, 0x70, 0x00,  // ---------OOO--------....
    0x00, 0x70, 0x00,  // ---------OOO--------....
    0x00, 0x60, 0x00,  // ---------OO---------....
    0x00, 0x40, 0x00,  // ---------O----------....
    0x00, 0x00, 0x00,  // --------------------....
    0x00, 0x00, 0x00,  // --------------------....

    // ASCII: 57416, char width: 29
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...
    0x00, 0x07, 0x00, 0x00,  // -------------OOO-------------...
    0x00, 0xff, 0xf8, 0x00,  // --------OOOOOOOOOOOOO--------...
    0x07, 0xff, 0xfe, 0x00,  // -----OOOOOOOOOOOOOOOOOO------...
    0x1f, 0xff, 0xff, 0x80,  // ---OOOOOOOOOOOOOOOOOOOOOO----...
    0x3f, 0xc0, 0x3f, 0xe0,  // --OOOOOOOO--------OOOOOOOOO--...
    0x7e, 0x07, 0x07, 0xf0,  // -OOOOOO------OOO-----OOOOOOO-...
    0x7c, 0x7f, 0xf1, 0xf0,  // -OOOOO---OOOOOOOOOOO---OOOOO-...
    0x31, 0xff, 0xfc, 0x60,  // --OO---OOOOOOOOOOOOOOO---OO--...
    0x07, 0xff, 0xfe, 0x00,  // -----OOOOOOOOOOOOOOOOOO------...
    0x07, 0xf0, 0x7f, 0x00,  // -----OOOOOOO-----OOOOOOO-----...
    0x07, 0x80, 0x1f, 0x00,  // -----OOOO----------OOOOO-----...
    0x03, 0x1f, 0x86, 0x00,  // ------OO---OOOOOO----OO------...
    0x00, 0x7f, 0xe0, 0x00,  // ---------OOOOOOOOOO----------...
    0x00, 0xff, 0xf0, 0x00,  // --------OOOOOOOOOOOO---------...
    0x00, 0x7f, 0xf0, 0x00,  // ---------OOOOOOOOOOO---------...
    0x00, 0x30, 0x60, 0x00,  // ----------OO-----OO----------...
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...
    0x00, 0x0f, 0x00, 0x00,  // ------------OOOO-------------...
    0x00, 0x07, 0x00, 0x00,  // -------------OOO-------------...
    0x00, 0x02, 0x00, 0x00,  // --------------O--------------...
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...
    0x00, 0x00, 0x00, 0x00,  // -----------------------------...

    // ASCII: 57417, char width: 32
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xcf, 0xff, 0xff, 0xe6,  // OO--OOOOOOOOOOOOOOOOOOOOOOO--OO-
    0xcf, 0xff, 0xff, 0xe7,  // OO--OOOOOOOOOOOOOOOOOOOOOOO--OOO
    0xcf, 0xff, 0xff, 0xe3,  // OO--OOOOOOOOOOOOOOOOOOOOOOO---OO
    0xcf, 0xff, 0xff, 0xe1,  // OO--OOOOOOOOOOOOOOOOOOOOOOO----O
    0xcf, 0xff, 0xff, 0xe1,  // OO--OOOOOOOOOOOOOOOOOOOOOOO----O
    0xcf, 0xff, 0xff, 0xe1,  // OO--OOOOOOOOOOOOOOOOOOOOOOO----O
    0xcf, 0xff, 0xff, 0xe1,  // OO--OOOOOOOOOOOOOOOOOOOOOOO----O
    0xcf, 0xff, 0xff, 0xe1,  // OO--OOOOOOOOOOOOOOOOOOOOOOO----O
    0xcf, 0xff, 0xff, 0xe7,  // OO--OOOOOOOOOOOOOOOOOOOOOOO--OOO
    0xcf, 0xff, 0xff, 0xe7,  // OO--OOOOOOOOOOOOOOOOOOOOOOO--OOO
    0xcf, 0xff, 0xff, 0xe6,  // OO--OOOOOOOOOOOOOOOOOOOOOOO--OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------

    // ASCII: 57418, char width: 32
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xcf, 0xff, 0xfc, 0x06,  // OO--OOOOOOOOOOOOOOOOOO-------OO-
    0xcf, 0xff, 0xfc, 0x07,  // OO--OOOOOOOOOOOOOOOOOO-------OOO
    0xcf, 0xff, 0xfc, 0x03,  // OO--OOOOOOOOOOOOOOOOOO--------OO
    0xcf, 0xff, 0xfc, 0x01,  // OO--OOOOOOOOOOOOOOOOOO---------O
    0xcf, 0xff, 0xfc, 0x01,  // OO--OOOOOOOOOOOOOOOOOO---------O
    0xcf, 0xff, 0xfc, 0x01,  // OO--OOOOOOOOOOOOOOOOOO---------O
    0xcf, 0xff, 0xfc, 0x01,  // OO--OOOOOOOOOOOOOOOOOO---------O
    0xcf, 0xff, 0xfc, 0x01,  // OO--OOOOOOOOOOOOOOOOOO---------O
    0xcf, 0xff, 0xfc, 0x07,  // OO--OOOOOOOOOOOOOOOOOO-------OOO
    0xcf, 0xff, 0xfc, 0x07,  // OO--OOOOOOOOOOOOOOOOOO-------OOO
    0xcf, 0xff, 0xfc, 0x06,  // OO--OOOOOOOOOOOOOOOOOO-------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------

    // ASCII: 57419, char width: 32
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xdf, 0xff, 0x00, 0x06,  // OO-OOOOOOOOOOOOO-------------OO-
    0xdf, 0xff, 0x00, 0x07,  // OO-OOOOOOOOOOOOO-------------OOO
    0xdf, 0xff, 0x00, 0x03,  // OO-OOOOOOOOOOOOO--------------OO
    0xdf, 0xff, 0x00, 0x01,  // OO-OOOOOOOOOOOOO---------------O
    0xdf, 0xff, 0x00, 0x01,  // OO-OOOOOOOOOOOOO---------------O
    0xdf, 0xff, 0x00, 0x01,  // OO-OOOOOOOOOOOOO---------------O
    0xdf, 0xff, 0x00, 0x01,  // OO-OOOOOOOOOOOOO---------------O
    0xdf, 0xff, 0x00, 0x01,  // OO-OOOOOOOOOOOOO---------------O
    0xdf, 0xff, 0x00, 0x07,  // OO-OOOOOOOOOOOOO-------------OOO
    0xdf, 0xff, 0x00, 0x07,  // OO-OOOOOOOOOOOOO-------------OOO
    0xcf, 0xff, 0x00, 0x06,  // OO--OOOOOOOOOOOO-------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------

    // ASCII: 57420, char width: 32
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xcf, 0xe0, 0x00, 0x06,  // OO--OOOOOOO------------------OO-
    0xcf, 0xe0, 0x00, 0x07,  // OO--OOOOOOO------------------OOO
    0xcf, 0xe0, 0x00, 0x03,  // OO--OOOOOOO-------------------OO
    0xcf, 0xe0, 0x00, 0x01,  // OO--OOOOOOO--------------------O
    0xcf, 0xe0, 0x00, 0x01,  // OO--OOOOOOO--------------------O
    0xcf, 0xe0, 0x00, 0x01,  // OO--OOOOOOO--------------------O
    0xcf, 0xe0, 0x00, 0x01,  // OO--OOOOOOO--------------------O
    0xcf, 0xe0, 0x00, 0x01,  // OO--OOOOOOO--------------------O
    0xcf, 0xe0, 0x00, 0x07,  // OO--OOOOOOO------------------OOO
    0xcf, 0xe0, 0x00, 0x07,  // OO--OOOOOOO------------------OOO
    0xcf, 0xe0, 0x00, 0x06,  // OO--OOOOOOO------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------

    // ASCII: 57421, char width: 32
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x07,  // OO---------------------------OOO
    0xc0, 0x00, 0x00, 0x03,  // OO----------------------------OO
    0xc0, 0x00, 0x00, 0x01,  // OO-----------------------------O
    0xc0, 0x00, 0x00, 0x01,  // OO-----------------------------O
    0xc0, 0x00, 0x00, 0x01,  // OO-----------------------------O
    0xc0, 0x00, 0x00, 0x01,  // OO-----------------------------O
    0xc0, 0x00, 0x00, 0x01,  // OO-----------------------------O
    0xc0, 0x00, 0x00, 0x07,  // OO---------------------------OOO
    0xc0, 0x00, 0x00, 0x07,  // OO---------------------------OOO
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xc0, 0x00, 0x00, 0x06,  // OO---------------------------OO-
    0xff, 0xff, 0xff, 0xfe,  // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO-
    0x7f, 0xff, 0xff, 0xfc,  // -OOOOOOOOOOOOOOOOOOOOOOOOOOOOO--
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------
    0x00, 0x00, 0x00, 0x00,  // --------------------------------

    // ASCII: 57422, char width: 21
    0x01, 0xfc, 0x00,  // -------OOOOOOO-------...
    0x07, 0xff, 0x00,  // -----OOOOOOOOOOO-----...
    0x0f, 0xdf, 0x80,  // ----OOOOOO-OOOOOO----...
    0x1f, 0xcf, 0xc0,  // ---OOOOOOO--OOOOOO---...
    0x1f, 0xc7, 0xe0,  // ---OOOOOOO---OOOOOO--...
    0x1f, 0xc3, 0xe0,  // ---OOOOOOO----OOOOO--...
    0x3f, 0xc1, 0xe0,  // --OOOOOOOO-----OOOO--...
    0x3d, 0xc8, 0xf0,  // --OOOO-OOO--O---OOOO-...
    0x3c, 0xcc, 0xf0,  // --OOOO--OO--OO--OOOO-...
    0x3e, 0x49, 0xf0,  // --OOOOO--O--O--OOOOO-...
    0x3f, 0x03, 0xf0,  // --OOOOOO------OOOOOO-...
    0x3f, 0x87, 0xf0,  // --OOOOOOO----OOOOOOO-...
    0x3f, 0x8f, 0xf0,  // --OOOOOOO---OOOOOOOO-...
    0x3f, 0x87, 0xf0,  // --OOOOOOO----OOOOOOO-...
    0x3f, 0x03, 0xf0,  // --OOOOOO------OOOOOO-...
    0x3e, 0x49, 0xf0,  // --OOOOO--O--O--OOOOO-...
    0x3c, 0xcc, 0xf0,  // --OOOO--OO--OO--OOOO-...
    0x3d, 0xc8, 0xf0,  // --OOOO-OOO--O---OOOO-...
    0x3f, 0xc1, 0xe0,  // --OOOOOOOO-----OOOO--...
    0x1f, 0xc3, 0xe0,  // ---OOOOOOO----OOOOO--...
    0x1f, 0xc7, 0xe0,  // ---OOOOOOO---OOOOOO--...
    0x1f, 0xcf, 0xc0,  // ---OOOOOOO--OOOOOO---...
    0x0f, 0xdf, 0x80,  // ----OOOOOO-OOOOOO----...
    0x07, 0xff, 0x00,  // -----OOOOOOOOOOO-----...
    0x01, 0xfc, 0x00,  // -------OOOOOOO-------...
};

/*Store the start index of the glyphs in the bitmap array*/
static const uint32_t symbol_25_feedback_map[] = 
{
     0, 50, 100, 175, 275, 350, 400, 500, 
    575, 675, 775, 875, 975, 1075, 1175, 
};

/*Store the width (column count) of each glyph*/
static const uint8_t symbol_25_feedback_width[] = 
{
    11, 16, 23, 25, 20, 13, 25, 20, 
    29, 32, 32, 32, 32, 32, 21, 
};

static font_t symbol_25_feedback_dsc = 
{
#if TXT_UTF8 == 0
    192,            /*First letter's unicode */
    223,            /*Last letter's unicode */
#else
    57408,        /*First letter's unicode */
    57439,        /*Last letter's unicode */
#endif
    25,        /*Letters height (rows) */
    symbol_25_feedback_bitmap,    /*Glyph's bitmap*/
    symbol_25_feedback_map,    /*Glyph start indexes in the bitmap*/
    symbol_25_feedback_width,    /*Glyph widths (columns)*/
};

/*Function pointer which gives a pointer to the dsc. variable*/
font_t * symbol_25_feedback_get_dsc(void)
{
    return &symbol_25_feedback_dsc;
}


#endif /*SYMBOL_25_FEEDBACK_H*/
