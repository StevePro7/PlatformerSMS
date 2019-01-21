#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_STATES				4
#define TILE_X_OFFSET			1
#define GAME_X_OFFSET			TILE_X_OFFSET * 8

#define SPRITE_TILES_OFFSET		128

#define COLS	15
#define ROWS	12

#define CR	'\r'				// 0x0d
#define LF	'\n'				// 0x0a

const unsigned char list_sprite_tile_offset[] =
{
	SPRITE_TILES_OFFSET + 0,
	SPRITE_TILES_OFFSET + 8,
	SPRITE_TILES_OFFSET + 16,
	SPRITE_TILES_OFFSET + 24,
	SPRITE_TILES_OFFSET + 32,
};

#endif//_GLOBAL_MANAGER_H_