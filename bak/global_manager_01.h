#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_SCREEENS			9
#define MAX_ENEMIES				4
#define MAX_BLOCK_TILES			9

#define TILE_X_OFFSET			0							// TODO delete after confirm not required!
//#define GAME_X_OFFSET			TILE_X_OFFSET * 8			// TODO delete
//#define SPRITE_TILES_OFFSET		128
//#define SPRITE_TILES_OFFSET		256						// TODO delete as was used before but now dead code!
#define SPRITE_TILES_NUMBER		12

#define PLAYER_SPRITE_TILE		256
#define ENEMYX_SPRITE_TILE		388
#define INVALID_INDEX			-1

#define MAX_ROWS				12
#define MAX_COLS				16


#define TILE_WIDE				16
#define TILE_HIGH				16

#define ANIMATE_MOVE_MAX		5
#define ANIMATE_IDX_LEFT		1
#define ANIMATE_IDX_RGHT		6

//#define COLS	15
//#define ROWS	12
//extern const unsigned int list_sprite_tile_offset[];
//extern const unsigned char *stageinitdata[];

int myabs( int v );

#endif//_GLOBAL_MANAGER_H_