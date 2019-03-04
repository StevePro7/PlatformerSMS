@echo off
REM echo Execute bmp2tile

cd sprites

REM Sprites

REM Player
cd player
bmp2tile.exe raw\Idle.png -savetiles "player_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "..\master\Sprites (palette).bin" -fullpalette  -spritepalette -exit

cd ..
folder2c player player

REM MonsterA
cd enemyA
bmp2tile.exe raw\Idle.png -savetiles "enemyA_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0
bmp2tile.exe raw\Run_Left_01.png -savetiles "enemyA_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "enemyA_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..
folder2c enemyA enemyA


REM Palette
folder2c master master


REM build
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 master.c

del *.asm > nul
del *.lst > nul
del *.sym > nul