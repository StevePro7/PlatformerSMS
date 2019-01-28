@echo off
REM echo Generate levels

cd banks

folder2c bank2 bank2 2
folder2c bank3 bank3 3
folder2c bank4 bank4 4

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK4 bank4.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..