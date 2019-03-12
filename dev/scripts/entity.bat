@echo off
REM echo Execute bmp2tile

REM Sprites
cd sprites

REM Player
cd player
bmp2tile.exe raw\Idle.png -savetiles "player_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "..\master\Sprites (palette).bin" -fullpalette  -spritepalette -exit
bmp2tile.exe raw\Run_Left_01.png -savetiles "player_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "player_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_03.png -savetiles "player_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_04.png -savetiles "player_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_05.png -savetiles "player_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_06.png -savetiles "player_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_07.png -savetiles "player_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_08.png -savetiles "player_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_09.png -savetiles "player_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_10.png -savetiles "player_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_01.png -savetiles "player_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_02.png -savetiles "player_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_03.png -savetiles "player_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_04.png -savetiles "player_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_05.png -savetiles "player_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_06.png -savetiles "player_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_07.png -savetiles "player_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_08.png -savetiles "player_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_09.png -savetiles "player_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_10.png -savetiles "player_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
cd ..

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

REM MonsterB
cd enemyB
bmp2tile.exe raw\Idle.png -savetiles "enemyB_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_01.png -savetiles "enemyB_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "enemyB_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_03.png -savetiles "enemyB_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_04.png -savetiles "enemyB_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_05.png -savetiles "enemyB_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_06.png -savetiles "enemyB_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_07.png -savetiles "enemyB_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_08.png -savetiles "enemyB_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_09.png -savetiles "enemyB_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_10.png -savetiles "enemyB_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_01.png -savetiles "enemyB_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_02.png -savetiles "enemyB_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_03.png -savetiles "enemyB_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_04.png -savetiles "enemyB_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_05.png -savetiles "enemyB_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_06.png -savetiles "enemyB_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_07.png -savetiles "enemyB_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_08.png -savetiles "enemyB_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_09.png -savetiles "enemyB_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_10.png -savetiles "enemyB_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
cd ..

REM MonsterC
cd enemyC
bmp2tile.exe raw\Idle.png -savetiles "enemyC_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_01.png -savetiles "enemyC_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "enemyC_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_03.png -savetiles "enemyC_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_04.png -savetiles "enemyC_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_05.png -savetiles "enemyC_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_06.png -savetiles "enemyC_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_07.png -savetiles "enemyC_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_08.png -savetiles "enemyC_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_09.png -savetiles "enemyC_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_10.png -savetiles "enemyC_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_01.png -savetiles "enemyC_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_02.png -savetiles "enemyC_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_03.png -savetiles "enemyC_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_04.png -savetiles "enemyC_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_05.png -savetiles "enemyC_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_06.png -savetiles "enemyC_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_07.png -savetiles "enemyC_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_08.png -savetiles "enemyC_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_09.png -savetiles "enemyC_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_10.png -savetiles "enemyC_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
cd ..

REM MonsterD
cd enemyD
bmp2tile.exe raw\Idle.png -savetiles "enemyD_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_01.png -savetiles "enemyD_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_02.png -savetiles "enemyD_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_03.png -savetiles "enemyD_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_04.png -savetiles "enemyD_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_05.png -savetiles "enemyD_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_06.png -savetiles "enemyD_run_left_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_07.png -savetiles "enemyD_run_left_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_08.png -savetiles "enemyD_run_left_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_09.png -savetiles "enemyD_run_left_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Left_10.png -savetiles "enemyD_run_left_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_01.png -savetiles "enemyD_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_02.png -savetiles "enemyD_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_03.png -savetiles "enemyD_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_04.png -savetiles "enemyD_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_05.png -savetiles "enemyD_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_06.png -savetiles "enemyD_run_rght_06 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_07.png -savetiles "enemyD_run_rght_07 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_08.png -savetiles "enemyD_run_rght_08 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_09.png -savetiles "enemyD_run_rght_09 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\Run_Rght_10.png -savetiles "enemyD_run_rght_10 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
cd ..

REM folder2C
folder2c player player
folder2c enemyA enemyA
folder2c enemyB enemyB
folder2c enemyC enemyC
folder2c enemyD enemyD
folder2c master master

REM build
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 player.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemyA.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemyB.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemyC.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemyD.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 master.c

del *.asm > nul
del *.lst > nul
del *.sym > nul