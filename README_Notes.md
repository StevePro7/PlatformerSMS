DESCRIPTION
# Platformer Explorer
Platformer Explorer game for the SMS Power! 2019 Competition.

###### RELEASE
Wednesday, 27th March 2019

###### INTRO
Platform Explorer is a port of the XNA Platformer starter kit for the Sega Master System.

###### INSTRUCTIONS
Move left and right and fire1 to jump.  Hold fire2 to reset player during play.
Easy or hard difficulty.  Avoid all enemies + guards and watch out for the pits!

Due to time constraints, there are currently only 20x levels.  More levels are coming soon...!
There is capacity for 80-100 levels.  Pls let me know if you'd like to design some levels :)

###### TOOLS
- Programming:	devkitSMS
- Compiler		sdcc 3.6
- Languages:	C / Z80
- Visual Studio 2015
- Graphics:		BMP2Tile / GIMP2 / paint.net
- Music:		VGM2PSG
- Assembler:	WLA-DX
- Emulators:	Emulicious / Fusion / Meka

###### SOURCE CODE
http://github.com/SteveProXNA/PlatformerExplorerSMS

###### ROM HACKING
You can hack this ROM!  
Download and dump PlatformExplorer.sms into Hex Editor, e.g. HxD, and modify bytes:
- 0x004F	DelaySpeed	Used during dev disables screen delays.
- 0x0050	Invincible	Non-zero value enables auto invincible.
- 0x0051	Difficulty	Set value to 1=Hard otherwise use Easy.
- 0x0052	World No.	Set start world no to zero-based value.
- 0x0053	Round No.	Set start round no to zero-based value.
- 0x0054	Music Off	Set 0=music to play otherwise disabled.
- 0x0055	Sound Off	Set 0=sound to play otherwise disabled.
- 0x0056	Enemy move	Set value non-zero to disable movement.

###### CHEAT
Press button 2 five times and you will be invincible each game this is actioned.

###### CREDITS
Extra special thanks to: sverx for devkitSMS https://github.com/sverx/devkitSMS
<br />
Plus shout out to eruiz00 as I used many programming tricks from "Astro Force"
<br />
Also, I used a lot of programming tricks from haroldoop's various code samples.
<br />
As always, thanks goes to:
<br />
Maxim, Martin, Ville Helin, Steve Snake, Bock + Calindro

###### SOCIAL MEDIA
- You Tube https://youtu.be/6VpGrZLTGTk			TODO

###### OUTSTANDING
Some extra sound effects could be cool plus more animations e.g. when you pass each level.

###### DOCUMENTATION
Links to documentation on games written for the Sega Master System using devkitSMS:
http://steveproxna.blogspot.com/2017/09/devkitsms-programming-setup.html
<br />
http://steveproxna.blogspot.com/2017/11/devkitsms-programming-sample.html
<br />
http://steveproxna.blogspot.com/2018/03/devkitsms-programming-sample-ii.html
 
###### COMPANY BIO
StevePro Studios is an independent game developer that builds and publishes 80s retro arcade video games!
<br />
Founded by Steven Boland "SteveProXNA" (Jan-2007) a "one man team of one" currently based in Dublin, Ireland.

Previous Sega-based retro games published include
"3D City" available here:
- iOS		https://apple.co/2BE6LSj
- Android	https://goo.gl/j3QG5G
- PC		https://bit.ly/2TzV30O

"Candy Kid" available here:
- iOS		http://apple.co/1QcidUk
- Android	http://goo.gl/5rWsYO
- PC		http://amzn.to/1QiHM9d

###### CONTACT
- Blog:		http://steveproxna.blogspot.com
- Email:	steven_boland@hotmail.com
- Twitter:	[@SteveProXNA](http://twitter.com/SteveProXNA)
