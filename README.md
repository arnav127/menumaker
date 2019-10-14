# MenuMaker

Menumaker is a library that can be used to create menus for programs. It has an easy to use way of adding  entries for menus and displaying them.
*This library is currently only supported on Linux systems and is currently being ported to Windows.*

## Features
- Easy to use method.
- Use of arrow keys for navigation.
- Centering of menu in the terminal, even after resizing.
- Highlighting menu entries.
- Displaying description for all menu entries currently highlighted.
- Optional return value or default values assigned serial wise.

## Method
- Place the files in your working directory.
- Include the header file menu.h.
		 `#include "menu.h"`
- Make an object of class menu where the menu has to be created. 
	`menu obj;`
- Add entries to the menu class using the function add. The default values for return value is assigned serial number wise and the default description is null.
 `obj.add("Entry Name", return_value, "Description");`
 The return value and description are optional. Entries can also be added as: `obj.add("Entry Name");`
 - After adding all the menu entries call the function display, which returns an integer value corresponding to the menu entry number which can then be used for switch case comparison.
  `int x = obj.display();`
