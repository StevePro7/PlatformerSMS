#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_SCREEENS			7
#define MAX_ENEMIES				6
#define TILE_X_OFFSET			0
#define GAME_X_OFFSET			TILE_X_OFFSET * 8

//#define SPRITE_TILES_OFFSET		128
#define SPRITE_TILES_OFFSET		256
#define SPRITE_TILES_NUMBER		12
#define MAX_BLOCK_TILES			9

#define INVALID_INDEX			-1

#define MAX_ROWS				12
#define MAX_COLS				15

#define COLS	15
#define ROWS	12

#define TILE_WIDE				16
#define TILE_HIGH				16



extern const unsigned int list_sprite_tile_offset[];
extern const unsigned char *stageinitdata[];

#endif//_GLOBAL_MANAGER_H_