# PlatformerSMS
Placeholder repo for PlatformerSMS

PLATFORM
EXPLORER
Warner the Explorer
https://yhoo.it/2HdDJfu

17/03/2019
Algorithm for centered text:
get total value of text width (if odd number then add 1)
subtract width from 30, halve then add 2
e.g.
PRESS START = 11x chars [12x chars]
30-12 = 18 / 2 = 9 + 2 = 11X posnY

TODO
Title screen want to check for cheat mode => god_mode
Static screens must add sound effects [wrapped with audio manager hack ]

15/03/2019
IMPORTANT
Must check collision detection btwn player and enemy(s) if player below enemy and jump thru platform to hit enemy - can die
$ currently optional platform
Easy	visible
Hard	hidden
I believe that platform is better than block tile as can jump thru them non blocking

14/03/2019
Wonderboy level select cheat

Add new screen checklist
Create *_screen.h and *_screen.c file
Copy stub methods from existing screen
Rename stub methods accordingly
Update header guard names and file reference names
Include whatever header files are necessary
Update the enum_manager by add new screen type
Update global_manager by increase no. screens
Update screen_manager by include new screen header file
Update screen_manager by adding new load + update function pointers to existing arrays
Update build.bat by adding sdcc -c for *_screen.c AND *_screen.rel
DON'T FORGET to update the build.bat to include screen_manager.c and any other dependencies
Take screen for test drive in main.c

14/03/2019
Title tiles loaded start 128 and finish 342	bmp2tile says 221 tiles for both
If round up to nearest 16x tiles then next block would be 352 [22*16] which would leave 96 tiles left for title "sprites" [tiles]
96x tiles / 12 tiles per entity = 8x entities maximum which would be plenty here...

12/03/2019
Hack ROM for invincibility.  If/when have pits then load the level as normal, calculate enemy horizontal range with impassable tiles
But before complete, check if (invincible) then update any/all passsble pits files on bottom row with impassable but draw debug square
This way enemy has range as before but player cannot fall thru pits to death.

Hacker options
don't think that I would configure unlimited continues but just enforce easy=YES or hard=NO

Also, should check on level load in play_screen if there no pits at all - if not then no need to check eash frame

08/03/2019
Level budgets
Decided for no scrolling on level.  Therefore, each level will be 16x12 tiles [of 16x16 tile]
which means 216 bytes per level that is (16+2) * 12
There is 16KB available per bank which means that there is availability for how many levels?

07/03/2019
Animation budget calculated: 192 tiles = 12x tiles per frame * 16x frames
16x frames equals
Player	1x idle + 5x anims	6
EnemyX	1x idle + 5x anims	6
EnemyN	1x idle * 3x 		3
Total						15			1x spare

Sprite tiles 
I wanted to stress test this a bit more to confirm 256 sprite tiles and how to use them
Reference:
https://segaretro.org/Sega_Master_System/Technical_specifications
Sprites: 16 colors (15 opaque, 1 transparent) per sprite, up to 256 tiles/patterns in VRAM used by sprites,[4] collision detection[22]

First half

Second half
devkit_SMS_useFirstHalfTilesforSprites_False();
Tiles 256-447
There are 192 sprite tiles in the second half, that is 256 + 192 = 448

06/03/2019
Can I use function pointer for animation for example
draw[0] = draw_idle
draw[1] = draw_left
draw[2] = draw_rght
Example	DuckSlayer
void(*draw)(void *);
void draw_actor_player(void *p)
draw_actor_player

Spent the rest of this evening wrestling with the sprite tile limitations
and when I constantly load sprite tiles during game play than this kills performance!

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
