REM bank4	Levels half#1
@echo off

cd banks

folder2c bank4 bank4 4

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK4 bank4.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..