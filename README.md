# PlatformerSMS
Placeholder repo for PlatformerSMS

PLATFORM
EXPLORER
Warner the Explorer
https://yhoo.it/2HdDJfu

28/03/2019
TODO
01.	DONE
PlayScreen check if down() also then move back to BeginScreen
otherwise reset player as because

02.	DONE
Shorten Gem screen delay + test

03.	DONE
mklink to banks folder and write code to check bank4 + bank5 duplicates

04.	DONE
Rename ViewScreen to SelectScreen.  Wire up 3x fire2 on DiffScreen to navigate there
Wire up fire2 to pop back.  Leave the other input the same

05.
Sound effects test

27/03/2019
Intro length
1x3
2x3
3x3
4x1

DON'T FORGET to back out the changes used during level testing:
search for stevepro\Personal\_Platformer\VGMs\TrivialPursuit-SMS

SHA
7f8bdcec22811a53e61cd40dd84c27e5eb79bee9

ScoreManager
HackManager

Refine the following levels:
0309
C:\Github\StevePro7\PlatformerSMS\bak\banks07\bank4

BUG
0207
..#####....$###.
..#####.F..$###.
F = fail to fall thru pit - not sure why this is different
0208	=>	0305

26/03/2019
Music summary:
Ninja Gaiden (GG) - 01 - Main Theme						mus_game04.psg
D:\Steven\Personal\_Platformer\VGMs\NinjaGaiden-GG
renamed mus_game04 to mus_game02 for sequential

Ninja Gaiden - 03 - Story								mus_game01.psg
Ninja Gaiden - 02 - Title Screen						mus_game01.psg	ORGiginally but sounds like mus_game03 so swapped
Ninja Gaiden - 10 - The Land of Enemy					mus_game03.psg
D:\Steven\Personal\_Platformer\VGMs\NinjaGaiden-SMS		

TOO LARGE
//Ninja Gaiden (GG) - 02 - Assault						mus_game05
//Ninja Gaiden (GG) - 03 - Smuggling					mus_game06
//Ninja Gaiden - 11 - Raid								mus_game02.psg

26/03/2019
Big optimization today: took out the myabs() function and replaced with custom logic
to determine which sign to check and noticed a massive improved noticeable more on 60FPS NTSC
However, there is still an issue when there are too many platform blocks so use sparingly!
Ditto applies to optional platform blocks
Finally, if having any issue with level not rendering correctly then ensure full re-build!

25/03/2019
C:\stevepro\roms\SegaStuff\SMSpower\MusicTOOLS

Trivial Pursuit - 014 - Hen Wlad Fy Nhadau.vgm
Trivial Pursuit - 015 - Hymn to Liberty.vgm
Trivial Pursuit - 016 - Allahu Akbar.vgm				MAYBE
Trivial Pursuit - 017 - Nunarput Utoqqarsuanngoravit	MAYBE
Trivial Pursuit - 018 - Lofsongur
Trivial Pursuit - 026 - The Rain In Spain				maybe
Trivial Pursuit - 027 - Scarborough Fair
Trivial Pursuit - 201 - Scarborough Fair
Trivial Pursuit - 028 - Piano Sonata No. 14 in C Sharp Minor (Moonlight Sonata)		TOO long?
Trivial Pursuit - 036 - Grande Valse Villageoise (The Garland Waltz)
Trivial Pursuit - 044 - (Unknown)
Trivial Pursuit - 047 - La Primavera (Spring)
Trivial Pursuit - 054 - March of the Volunteers
Trivial Pursuit - 057 - Maria
Trivial Pursuit - 062 - (Unknown)

Trivial Pursuit - 190 - Minuet In G Major (Unused)
Trivial Pursuit - 243 - We Three Kings (Unused)
Trivial Pursuit - 257 - Herz und Mund und Tat und Leben, BWV 147 (Jesu, Joy of Man's Desiring)
Trivial Pursuit - 247 - Greensleeves
Trivial Pursuit - 229 - Tradition
Trivial Pursuit - 237 - Antioch
Trivial Pursuit - 221 - 9th Symphony, Movement IV (Ode to Joy)
C:\stevepro\Personal\_Platformer\VGMs\TrivialPursuit-SMS


23/03/2019
Polish
cont => ready want delay as can hold fire1 and jump when re-play

Do I want one generic memo box one size?
x   GAME   x
x COMPLETE x
x CONTINUE?x
x >YES >NO x
x>>YES >>NOx

Test, if free man, never greater than max [currenty=9]


23/03/2019
TODO
check the sprite edge case drawing on the 3x screens:
over / cont / beat

22/03/2019
TODO
void engine_player_manager_draw_idle()
Only draw sprites if not covered by center box - need to calculate X + Y positions


20/03/2019
IMPORTANT	TODO
Currently, I have the play screen check for Fire2 to hardcode go back to level select screen for testing!!

UPDATE
Backed out the changes outlined below because it caused to much data to be stored and configured
Plus the additional calculations required Abs() all of which impacted on performance
Therefore, will go with the simpler version...!

Stress testing
Max 2x enemys
Max 2x guards where the 2x guards are on the same plane causes noticeable lag "occasionally"
But 4x guards on one plane if fine OR 3x guards on one plane plus 1x enemy seems OK too
Cool thing now is that I can have 2x enemys on the same plane!

Enemy movement : if velX = 3 [max] then make tile width divisible by 3 ie 3, 6, 9, 12 contiguous tiles wide
This guarantees that enemy will not have to fill in tiny "blanks" towards the end.  Obv 1+2+4 will work OK but 4 is too "fast"

Therefore, mental note: if I do want flexibility of having velX=3 for an enemy at any time then
it is up to me to "remember" to have enemy platform width divisible by 3 regardless of difficulty level ie no optional platforms here!

SUMMARY enemy movement
Want flexibility of enemy velX=1,2,3 at any stage irrespective of difficulty level i.e. don't velX += difficulty
Instead make the difficulty harder by reducing the delay / pause between block moves and idle wait interval
NB: could modify this logic for "Eddie" i.e. velX += difficulty as pause between blocks = 0

19/03/2019
TODO
Do I want to split out the ready screen as dead goes here but also cont screen?

TODO
If player jump too high and land on enemy or guard then "force" posnY down so player is visible

Timed Build.bat script suddenly gave the following warning / errors:
https://stackoverflow.com/questions/34760066/unbalanced-parenthesis-batch-file
Unbalanced parenthesis.
Unbalanced parenthesis.
Missing operand.

Therefore, modified for one towards the bottom making tweaks and combine text from first


18/03/2019
Test2015_07_soundFX
E:\Steven\INSTALLATIONSEGA\sdcc2
OK / Advance			right.psg
Cheat, PowerUp			cheat.psg
Reset level / game		wrong.psg
Gem collect yellow		jump.psg


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

TODO
Do I want to change font manager to accept const for everything?
What prompted this was the stats_manager count_text; normally this would be const *array
but the current font_manager causes different const qualifier warning to display


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
Lemmings	NOT the tunes - where did I get these from?
Success		celebrate
Failure		die
Trivial Pursuit - 030 - Minuet in G Major
D:\Steven\Personal\_Platformer\VGMs\TrivialPursuit-SMS

Fanfare4	GameOver
Fanfare7	LevelStart?
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
