@echo off
REM echo Execute bmp2tile

cd ..\gfx

REM Tiles
REM hard code palette to ensure first is 0x00 and last is 0x3f
REM .db $00 $01 $05 $06 $06 $07 $05 $07 $07 $17 $1A $2A $0A $1F $0F $3F
REM bmp2tile.exe Tiles\font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -removedupes -planar -tileoffset  0 -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette
bmp2tile.exe Tiles\back_tiles.bmp -savetiles "back_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savetilemap "back_tiles (tilemap).bin" -savepalette "back_tiles (palette).bin" -fullpalette -exit

REM Sprites
bmp2tile.exe Sprites\Player_Idle.bmp -savetiles "Player_Idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "Sprites (palette).bin" -fullpalette  -spritepalette -exit
bmp2tile.exe Sprites\EnemyA_Idle_01.bmp -savetiles "EnemyA_Idle_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe Sprites\EnemyB_Idle_01.bmp -savetiles "EnemyB_Idle_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe Sprites\EnemyC_Idle_01.bmp -savetiles "EnemyC_Idle_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe Sprites\EnemyD_Idle_01.bmp -savetiles "EnemyD_Idle_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
cd ..\dev

folder2c ..\gfx gfx