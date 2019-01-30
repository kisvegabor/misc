# Miscellaneous Library

Some of the most important components:
* Dynamic memory manager with defrag. and memory monitoring 
* Simple task scheduler with priority and idle measurement
* File system interface to access different mediums easily  
* RAM FS
* FIFO
* Linked list
* Fonts
* etc

## Usage
1. Clone the repository into the root folder of your project: `git clone https://github.com/littlevgl/misc.git`
2. In your IDE add the project **root folder as include path**
3. Copy *misc/misc_conf_templ.h* as **misc_conf.h** to the project root folder
4. Delete the first `#if 0` and the last `#endif` to enable the file
5. Enable/disable or configure the components
6. To initialize the library `#include misc/misc.h` and call `misc_init()`
