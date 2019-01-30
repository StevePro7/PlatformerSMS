@echo off & setlocal

REM https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
set start=%time%

REM echo Build gfx.c and gfx.h from gfx folder
REM folder2c ..\gfx gfx

REM echo Build psg.c and psg.h from psg folder
REM folder2c ..\psg psg


REM echo Build gfx
REM sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

REM echo Build psg
REM sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c

cd source
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 global_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 content_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 font_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 sprite_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tile_manager.c

REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 input_manager.c

REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 common_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 render_manager.c

cd ..

REM echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


REM Do stuff to be timed here.
REM Alternatively, uncomment the line below to be able to
REM pass in the command to be timed when running this script.
REM cmd /c %*
set end=%time%

REM Calculate time taken in seconds, to the hundredth of a second.
REM Assumes start time and end time will be on the same day.
set options="tokens=1-4 delims=:."

for /f %options% %%a in ("%start%") do (
    set /a start_s="(100%%a %% 100)*3600 + (100%%b %% 100)*60 + (100%%c %% 100)"
    set /a start_hs=100%%d %% 100
)

for /f %options% %%a in ("%end%") do (
    set /a end_s="(100%%a %% 100)*3600 + (100%%b %% 100)*60 + (100%%c %% 100)"
    set /a end_hs=100%%d %% 100
)

set /a s=%end_s%-%start_s%
set /a hs=%end_hs%-%start_hs%

if %hs% lss 0 (
    set /a s=%s%-1
    set /a hs=100%hs%
)
if 1%hs% lss 100 set hs=0%hs%

echo.
echo Time taken: %s%.%hs% secs
echo.

REM echo Linking
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
..\crt0\crt0_sms.rel main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
source\_sms_manager.rel ^
source\global_manager.rel ^
source\hack_manager.rel ^
source\content_manager.rel ^
source\font_manager.rel ^
source\sprite_manager.rel ^
source\tile_manager.rel ^
source\input_manager.rel ^
source\common_manager.rel ^
source\render_manager.rel ^
gfx.rel

REM sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
REM -Wl-b_BANK2=0x8000 ^
REM -Wl-b_BANK3=0x8000 ^
REM -Wl-b_BANK4=0x8000 ^
REM -Wl-b_BANK5=0x8000 ^
REM ..\crt0\crt0_sms.rel main.rel ^
REM ..\lib\SMSlib.lib ^
REM ..\lib\PSGlib.rel ^
REM banks\bank2.rel ^
REM banks\bank3.rel ^
REM banks\bank4.rel ^
REM banks\bank5.rel ^
REM gfx.rel

REM echo Binary output
ihx2sms output.ihx output.sms

REM copy output.sms
copy output.sms ..\
REM copy output.sms ..\asm
REM cd ..\asm
REM smsexamine.exe output.sms
REM cd ..\dev


REM echo Delete
REM cd banks
REM del *.asm > nul
REM del *.lst > nul
REM del *.rel > nul
REM del *.sym > nul
REM cd ..

REM https://www.askingbox.com/question/batch-script-delete-file-if-it-exists
cd source
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

if exist "*.asm" del "*.asm" > nul
if exist "*.ihx" del "*.ihx" > nul
if exist "*.lk"  del "*.lk"  > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.map" del "*.map" > nul
if exist "*.noi" del "*.noi" > nul
REM if exist "*.rel" del "*.rel" > nul
if exist "*.sym" del "*.sym" > nul


C:\SEGA\Fusion\fusion.exe output.sms
REM C:\SEGA\Meka\mekaw.exe output.sms
REM java -jar C:\SEGA\Emulicious\emulicious.jar output.sms