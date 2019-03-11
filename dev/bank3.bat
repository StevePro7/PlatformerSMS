REM bank3	Generic sprite tiles
@echo off

cd banks
cd bank3

REM player
bmp2tile.exe raw\player\Idle.png -savetiles "player_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "sprites (palette).bin" -fullpalette  -spritepalette -exit
bmp2tile.exe raw\player\Run_Left_01.png -savetiles "player_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_02.png -savetiles "player_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_03.png -savetiles "player_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_04.png -savetiles "player_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_05.png -savetiles "player_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_06.png -savetiles "player_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_07.png -savetiles "player_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_08.png -savetiles "player_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_09.png -savetiles "player_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_10.png -savetiles "player_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_01.png -savetiles "player_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_02.png -savetiles "player_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_03.png -savetiles "player_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_04.png -savetiles "player_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_05.png -savetiles "player_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_06.png -savetiles "player_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_07.png -savetiles "player_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_08.png -savetiles "player_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_09.png -savetiles "player_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_10.png -savetiles "player_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

REM enemyX
bmp2tile.exe raw\enemyA\Idle.png -savetiles "enemyA_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyB\Idle.png -savetiles "enemyB_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyC\Idle.png -savetiles "enemyC_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyD\Idle.png -savetiles "enemyD_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..

folder2c bank3 bank3 3

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..