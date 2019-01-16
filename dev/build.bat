@echo off

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

C:\SEGA\Fusion\fusion.exe output.sms
REM C:\SEGA\Meka\mekaw.exe output.sms
REM java -jar C:\SEGA\Emulicious\emulicious.jar output.sms