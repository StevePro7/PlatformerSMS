# PlatformerSMS
Placeholder repo for PlatformerSMS

26/02/2019
In VS2015 here is how to "force" Visual Studio to use // for multi line comments
Reference:
https://stackoverflow.com/questions/14872680/visual-studio-c-multiline-comments
Triple click the starting line and while mouse click still held drag down the number of lines
you want to comment out... unclick and press the comment icon to multi comment using // style

14/02/2019
Here is a reference to the pedantic warning
https://juju.nz/src/juju/gbdk/src/branch/master/sdcc/support/Util/SDCCerr.c
conditional flow changed by optimizer '%s(%d)':so said EVELYN the modified DOG"

Here is how I got the warning and how I "removed" it:
initially the variables were declared as int but because max value could be 255
I changed the variables to unsigned char and now the compiler warning disappears


11/02/2019
Sprite palette
.db $00 $00 $01 $00 $11 $16 $25 $15 $15 $05 $27 $0B $2A $1A $2F $3F

spritesheet.bmp
E:\Steven\XNA\Platformer\SpriteBlackBG\Game\bin\x86\Debug

All black 64x64 sprites


05/02/2019
16x32 pixel
width goes like this 2px + 12px + 2px
i.e. 2px either side of the player / enemy sprites
if posX = 96 then can be range 94 (-2) to 98 (+2) either side of center tile
before hit wall on either side and stop on tile for idle animation for enemy

03/02/2019
Conclusive proof that cannot include *.cpp files in this type of project
https://stackoverflow.com/questions/9928238/unresolved-external-symbol-in-object-files

?ASlink-Warning-Undefined Global '_engine_scroll_manager_load' referenced by module 'main'
#include "scroll_manager.h"
#ifdef __cplusplus
extern "C"
{
#endif
void engine_scroll_manager_load()
{
}
#ifdef __cplusplus
}
#endif

31/01/2019
Math functions
did prototype testing on this before but couldn't find my code samples...!
Here is the header file to reference what math functions are available in SDCC
https://github.com/darconeous/sdcc/blob/master/device/include/math.h

29/01/2019
Build - maybe not able to split into C files
as need SMSlib.h in main.c for SMS header

Compare AstroForce with current build:
All tiles are loaded once and only once into Tile Viewer [VRAM]
just like Wonderboy
However, the Sprite Viewer is constantly changing [for animations]
Therefore, could current tiles in Tile Viewer
32 tile wide	8*4
01. 64 font
02. 64 back
Leaves 32*10=320 tiles left
Divide by 8 tiles per animations	16*32px
Equals enough space for 40 animations	8*40=320

28/01/2019
Can I dynamically determine the width of any given level by
dividing the array[] count by 12 as will always be 12 height
e.g.
should be 204 for "default" level i.e. 17 * 12 = 204 (17 = 15 + 2)

Buttons
Fire1		Speed
Fire2		Jump

21/01/2019
TODO
Re-arrange the tile bitmap so that the first index zero is 16x16 blank
And move the platform to #10. Also make a red gem while there
PS: do I want to do a 8x8 of all the corresponding tiles while there?

IMPORTANT
When designing levels ensure that the last line ends with carriage return
i.e.
1..11
1234561234512345

This will ensure CRLF for the level and COLS + 2 continues to work
Otherwise the first byte of the next level will be used..! 


bool true	1
bool false	0

but return type unsigned char otherwise warnings / errors


https://github.com/darconeous/sdcc/blob/master/device/include/math.h