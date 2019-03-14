REM bank3	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank3

bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "splash (tilemap).stmcompr" -exit
bmp2tile.exe raw\title6.png -savetiles "title6 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "title6 (tilemap).stmcompr" -exit
bmp2tile.exe raw\title6.png -savetiles "title8 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "title8 (tilemap).stmcompr" -exit

cd ..
folder2c bank3 bank3 3

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts