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
bmp2tile.exe raw\Idle.png -savetiles "enemyA_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_01.png -savetiles "enemyA_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "enemyA_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_03.png -savetiles "enemyA_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_04.png -savetiles "enemyA_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_05.png -savetiles "enemyA_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_06.png -savetiles "enemyA_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_07.png -savetiles "enemyA_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_08.png -savetiles "enemyA_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_09.png -savetiles "enemyA_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_10.png -savetiles "enemyA_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_01.png -savetiles "enemyA_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_02.png -savetiles "enemyA_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_03.png -savetiles "enemyA_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_04.png -savetiles "enemyA_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_05.png -savetiles "enemyA_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_06.png -savetiles "enemyA_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_07.png -savetiles "enemyA_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_08.png -savetiles "enemyA_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_09.png -savetiles "enemyA_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_10.png -savetiles "enemyA_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..
folder2c enemyA enemyA


REM Palette
folder2c master master


REM build
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 master.c

del *.asm > nul
del *.lst > nul
del *.sym > nul