@echo off
REM echo Execute bmp2tile

REM folder2C
folder2c master master
folder2c player player
folder2c enemyA enemyA 6
folder2c enemyB enemyB 6
folder2c enemyC enemyC 7
folder2c enemyD enemyD 7


REM build
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 master.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 player.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK6 enemyA.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK6 enemyB.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 enemyC.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 enemyD.c

del *.asm > nul
del *.lst > nul
del *.sym > nul