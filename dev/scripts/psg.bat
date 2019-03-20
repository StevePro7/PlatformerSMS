REM gfx		Commonly used gfx	not banked
@echo off

cd ..
cd ..
cd psg

bmp2tile.exe raw\back_tiles.bmp -savetiles "back_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savetilemap "back_tiles (tilemap).bin" -savepalette "back_tiles (palette).bin" -fullpalette -exit

cd ..
folder2c psg psg

cd dev
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..