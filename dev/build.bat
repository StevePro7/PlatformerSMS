@echo off

REM echo Build gfx.c and gfx.h from gfx folder
REM folder2c ..\gfx gfx

REM echo Build psg.c and psg.h from psg folder
REM folder2c ..\psg psg


REM echo Build gfx
REM sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

REM echo Build psg
REM sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c

REM echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


REM echo Linking
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
-Wl-b_BANK4=0x8000 ^
..\crt0\crt0_sms.rel main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
banks\bank4.rel ^
gfx.rel

REM echo Binary output
ihx2sms output.ihx output.sms

REM copy output.sms
copy output.sms ..\
REM copy output.sms ..\asm
REM cd ..\asm
REM smsexamine.exe output.sms
REM cd ..\dev


REM echo Delete
cd banks
rem del *.asm > nul
rem del *.lst > nul
REM del *.rel > nul
rem del *.sym > nul
cd ..

del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
REM del *.rel > nul
del *.sym > nul

REM C:\SEGA\Fusion\fusion.exe output.sms
REM C:\SEGA\Meka\mekaw.exe output.sms
java -jar C:\SEGA\Emulicious\emulicious.jar output.sms