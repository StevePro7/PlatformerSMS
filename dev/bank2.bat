REM bank2	Generic background tiles
@echo off

cd banks
cd bank2

bmp2tile.exe raw\back_tiles.bmp -savetiles "back_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savetilemap "back_tiles (tilemap).bin" -savepalette "back_tiles (palette).bin" -fullpalette -exit

cd ..

folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..