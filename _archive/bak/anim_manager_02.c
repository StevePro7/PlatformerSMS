#include "anim_manager.h"
#include "anim_object.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "_sms_manager.h"

//#define ANIMATE_MOVE_MAX		5
#define PLAYER_TILE_IDLE		256
#define PLAYER_TILE_LEFT		256 + 1 * SPRITE_TILES_NUMBER
#define PLAYER_TILE_RGHT		256 + 6 * SPRITE_TILES_NUMBER
#define ENEMYX_TILE_IDLE		388
//#define ENEMYX_TILE_MOVE		388 + 1 * SPRITE_TILES_NUMBER

// Private helper methods.
static void player_load( unsigned char index, unsigned int tile );
static void enemyA_load( unsigned char index, unsigned int tile );
static void enemyB_load( unsigned char index, unsigned int tile );
static void enemyC_load( unsigned char index, unsigned int tile );
static void enemyD_load( unsigned char index, unsigned int tile );

void engine_anim_manager_player_load_idle()
{
	player_load( 0, PLAYER_TILE_IDLE );
}
void engine_anim_manager_player_load_run()
{
	unsigned char index, loop;
	unsigned int tile;

	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = ANIMATE_IDX_LEFT + loop;
		tile = PLAYER_TILE_LEFT + loop * SPRITE_TILES_NUMBER;
		player_load( index, tile );

		index = ANIMATE_IDX_RGHT + loop;
		tile = PLAYER_TILE_RGHT + loop * SPRITE_TILES_NUMBER;
		player_load( index, tile );
	}
}
//void engine_anim_manager_player_load_run( unsigned char move_type, unsigned char half_type )
//{
//	unsigned char index, loop, start;
//	unsigned int tile;
//
//	start = move_type * ANIMATE_MOVE_MAX + half_type * ANIMATE_MOVE_MAX + 1;
//	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
//	{
//		index = start + loop;
//		tile = PLAYER_TILE_LEFT + loop * SPRITE_TILES_NUMBER;
//		player_load( index, tile );
//	}
//}
void engine_anim_manager_enemyX_load_idle()
{
	enemyA_load( 0, ENEMYX_TILE_IDLE + 0 * SPRITE_TILES_NUMBER );
	enemyB_load( 0, ENEMYX_TILE_IDLE + 1 * SPRITE_TILES_NUMBER );
	enemyC_load( 0, ENEMYX_TILE_IDLE + 2 * SPRITE_TILES_NUMBER );
	enemyD_load( 0, ENEMYX_TILE_IDLE + 3 * SPRITE_TILES_NUMBER );
}

//void engine_anim_manager_enemyX_load_move_run( unsigned char sprite_type, unsigned char move_type, unsigned char half_type )
//{
//	unsigned char index, loop, start;
//	unsigned int tile;
//
//	start = move_type * ANIMATE_MOVE_MAX + half_type * ANIMATE_MOVE_MAX + 1;
//	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
//	{
//		index = start + loop;
//		tile = ENEMYX_TILE_MOVE + loop * SPRITE_TILES_NUMBER;
//		
//		if( sprite_type_enemyA == sprite_type )
//		{
//			enemyA_load( index, tile );
//		}
//		else if( sprite_type_enemyB == sprite_type )
//		{
//			enemyB_load( index, tile );
//		}
//		else if( sprite_type_enemyC == sprite_type )
//		{
//			enemyC_load( index, tile );
//		}
//		else
//		{
//			enemyD_load( index, tile );
//		}
//	}
//}

//void engine_anim_manager_draw( unsigned char x, unsigned char y, unsigned int tile )
//{
//	devkit_SMS_addSprite_bulk( x, y, tile );
//
//	/*devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
//	devkit_SMS_addSprite( x + 16, y + 0, tile + 2 );
//
//	devkit_SMS_addSprite( x + 0, y + 8, tile + 3 );
//	devkit_SMS_addSprite( x + 8, y + 8, tile + 4 );
//	devkit_SMS_addSprite( x + 16, y + 8, tile + 5 );
//
//	devkit_SMS_addSprite( x + 0, y + 16, tile + 6 );
//	devkit_SMS_addSprite( x + 8, y + 16, tile + 7 );
//	devkit_SMS_addSprite( x + 16, y + 16, tile + 8 );
//
//	devkit_SMS_addSprite( x + 0, y + 24, tile + 9 );
//	devkit_SMS_addSprite( x + 8, y + 24, tile + 10 );
//	devkit_SMS_addSprite( x + 16, y + 24, tile + 11 );*/
//}


// Private helper methods.
static void player_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) player_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) player_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyA_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyA_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyA_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyB_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyB_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyB_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyC_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyC_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyC_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyD_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyD_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyD_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}