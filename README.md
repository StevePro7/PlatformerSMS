# PlatformerSMS
Placeholder repo for PlatformerSMS

PLATFORM
EXPLORER
Warner the Explorer
https://yhoo.it/2HdDJfu

05/03/2019
Did animation sprite test this morning with ROM banking and seems that the min-max is 256-447
i.e. for my 12x tile sprites [3x4] the max would be 448-12 = 436.

04/03/2019
Rough gestimate at the sprite tile loading
Assume there are 256 available sprite tiles then could do the following:
Player: Idle, RunLeft, RunRight, JumpLeft, JumpRight	= 5 * 12	= 60
EnemyA: Idle, RunLeft, RunRight							= 3 * 12	= 36
EnemyB: Idle, RunLeft, RunRight							= 3 * 12	= 36
EnemyC: Idle, RunLeft, RunRight							= 3 * 12	= 36
EnemyD: Idle, RunLeft, RunRight							= 3 * 12	= 36
																	 204
																	 
03/03/2019
VGMs
Trivial Pursuit - 030 - Minuet in G Major
D:\Steven\Personal\_Platformer\VGMs\TrivialPursuit-SMS

Fanfare4
Fanfare7
D:\Steven\Personal\_Platformer\VGMs\ZanGear-GG

GameOver
D:\Steven\Personal\_Platformer\VGMs\StreetsOfRageII-GG

IMPORTANT
be careful of data type incompatibility esp. when one is int but other is unsigned char
if the unsigned char overflows or becomes negative then this has dire consequences
i.e. can break code all over the place
Plus just setting one property from one object based on another with different type can cause issues

TODO
check player going below 192 to die method because player fell in pit
I want to refactor player_update() into smaller methods
I want to separate better the velX from input() to physics()

DONE
player jump higher than screen is causing issue
wire up player X,Y start on level into player manager	[currently hardcoded]
do I want to replace custom myabs() function with built in fabsa() function?

03/03/2019
While integrating all the player manager code there was a nasty bug with do_jump()
Basically, by setting deltaY to unsigned char this messes up everything for negative valocity
-11 should be interpreted as 65525 but comes out as 245 and is added to positionY
which causes posnY to always be added [not subtracted] and this wreaks havoc on collisionY
As a result, the collision tile map look up fails and the player falls "forever"


28/02/2019
Dynamic memory allocation example - checked online for malloc support and free in 
https://github.com/darconeous/sdcc/blob/master/device/include/malloc.h

IMPORTANT here
do NOT include <malloc.h> as will get the following errors
level_manager.c:7:20: fatal error: malloc.h: No such file or directory
compilation terminated.

To be on the safe side, should have static array memory allocation anyway just as a contingency plan...!

Also, reading about using malloc in the SMSpower forums I see this thread
http://www.smspower.org/forums/16785-SdccVsZ88dkAnd3MainBanks?highlight=malloc

On a different topic, do I want to use the proposed "--opt-code-size" compiler switch?
However, another quick google suggests that shouldn't use both speed + size options
Therefore, will leave --opt-code-speed for now as I currently have in my build script


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