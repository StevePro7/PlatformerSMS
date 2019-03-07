#include "global_manager.h"
#include "..\gfx.h"

const unsigned int list_sprite_tile_offset[] =
{
	SPRITE_TILES_OFFSET + 0 * SPRITE_TILES_NUMBER,
	SPRITE_TILES_OFFSET + 1 * SPRITE_TILES_NUMBER,
	SPRITE_TILES_OFFSET + 2 * SPRITE_TILES_NUMBER,
	SPRITE_TILES_OFFSET + 3 * SPRITE_TILES_NUMBER,
	SPRITE_TILES_OFFSET + 4 * SPRITE_TILES_NUMBER,
};

// TODO - am I going to use this?
//const unsigned char *stageinitdata[] =
//{
//	Player_Idle__tiles__psgcompr,
//	EnemyA_Idle__tiles__psgcompr,
//	EnemyB_Idle__tiles__psgcompr,
//	EnemyC_Idle__tiles__psgcompr,
//	EnemyD_Idle__tiles__psgcompr,
//};

// https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
int myabs( int v )
{
	return v * ( ( v < 0 ) * ( -1 ) + ( v > 0 ) );
}