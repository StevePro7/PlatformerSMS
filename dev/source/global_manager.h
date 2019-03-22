#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_SCREEENS			19
#define MAX_ENEMIES				4
#define MAX_BLOCK_TILES			9
#define MAX_SMALL_TILES			3

#define TILE_X_OFFSET			0							// TODO delete after confirm not required!
//#define GAME_X_OFFSET			TILE_X_OFFSET * 8			// TODO delete
//#define SPRITE_TILES_OFFSET		128
//#define SPRITE_TILES_OFFSET		256						// TODO delete as was used before but now dead code!
#define SPRITE_TILES_NUMBER		12
#define GUARDS_TILES_NUMBER		8

#define PLAYER_SPRITE_TILE		256
#define ENEMYX_SPRITE_TILE		388
#define INVALID_INDEX			-1

#define MAX_WORLDS				8	//4
#define MAX_ROUNDS				10

#define MAX_ROWS				12
#define MAX_COLS				16

#define TILE_WIDE				16
#define TILE_HIGH				16

#define SCREEN_TILE_WIDE		32
#define SCREEN_TILE_HIGH		24
#define SCREEN_TILE_LEFT		2

#define NUMBER_LIVES			4

#define ENEMYS_COLL_EASY		8
#define ENEMYS_COLL_HARD		12

#define MIN_POSITION_X			24
#define MAX_POSITION_X			248

#define ANIMATE_MOVE_MAX		5
#define ANIMATE_IDX_LEFT		1
#define ANIMATE_IDX_RGHT		6

// Custom function.
int myabs( int v );

#endif//_GLOBAL_MANAGER_H_