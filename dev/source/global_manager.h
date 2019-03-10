#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_SCREEENS			7
#define MAX_ENEMIES				6
#define TILE_X_OFFSET			0							// TODO delete after confirm not required!
//#define GAME_X_OFFSET			TILE_X_OFFSET * 8			// TODO delete

//#define SPRITE_TILES_OFFSET		128
#define SPRITE_TILES_OFFSET		256
#define SPRITE_TILES_NUMBER		12
#define MAX_BLOCK_TILES			9

#define PLAYER_TILE		256 + 0

#define INVALID_INDEX			-1

#define MAX_ROWS				12
#define MAX_COLS				16

//#define COLS	15
//#define ROWS	12

#define TILE_WIDE				16
#define TILE_HIGH				16

#define ANIMATE_MOVE_MAX		5
#define ANIMATE_IDX_LEFT		1
#define ANIMATE_IDX_RGHT		6

#define MAX_PLAYER_ANIMS	3
#define MAX_ENEMYX_ANIMS	21

extern const unsigned int list_sprite_tile_offset[];
//extern const unsigned char *stageinitdata[];

int myabs( int v );

#endif//_GLOBAL_MANAGER_H_