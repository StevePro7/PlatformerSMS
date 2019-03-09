#include "anim_manager.h"
#include "anim_object.h"
#include "global_manager.h"
#include "_sms_manager.h"

#define PLAYER_TILE_IDLE		256
#define PLAYER_TILE_MOVE		256 + 1 * SPRITE_TILES_NUMBER
#define ANIMATE_MOVE_MAX		5

void engine_anim_manager_player_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) player_anim_data[ index ];
	//const unsigned char bank = ( const unsigned char ) player_anim_bank[ index ];

	//devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
	//devkit_SMS_mapROMBank( 0 );
}

void engine_anim_manager_enemyA_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyA_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyA_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
	//devkit_SMS_mapROMBank( 0 );
}

void engine_anim_manager_enemyB_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyB_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyB_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
	//devkit_SMS_mapROMBank( 0 );
}

void engine_anim_manager_enemyC_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyC_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyC_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
	//devkit_SMS_mapROMBank( 0 );
}

void engine_anim_manager_enemyD_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyD_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyD_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
	//devkit_SMS_mapROMBank( 0 );
}

void engine_anim_manager_player_load_idle()
{
	//const unsigned char *data = ( const unsigned char * ) player_anim_data[ 0 ];
	//devkit_SMS_loadPSGaidencompressedTiles( data, PLAYER_TILE );
	engine_anim_manager_player_load( 0, PLAYER_TILE_IDLE );
}
void engine_anim_manager_player_load_run( unsigned char move_type, unsigned char half_type )
{
	unsigned char index, loop, start;
	unsigned int tile;

	start = move_type * ANIMATE_MOVE_MAX + half_type * ANIMATE_MOVE_MAX + 1;
	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = start + loop;
		tile = PLAYER_TILE_MOVE + loop * SPRITE_TILES_NUMBER;
		engine_anim_manager_player_load( index, tile );
	}
}

void engine_anim_manager_player_load_run_left( unsigned char half_type )
{
	unsigned char index, loop, start;
	unsigned int tile;

	start = half_type * ANIMATE_MOVE_MAX + 1;
	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = start + loop;
		tile = PLAYER_TILE_MOVE + loop * SPRITE_TILES_NUMBER;
		engine_anim_manager_player_load( index, tile );
	}
}
void engine_anim_manager_player_load_run_rght( unsigned char half_type )
{
	unsigned char index, loop, start;
	unsigned int tile;

	start = half_type * ANIMATE_MOVE_MAX + 1;
	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = start + loop;
		tile = PLAYER_TILE_MOVE + loop * SPRITE_TILES_NUMBER;
		engine_anim_manager_player_load( index, tile );
	}
}

void engine_anim_manager_draw( unsigned char x, unsigned char y, unsigned int tile )
{
	devkit_SMS_addSprite_bulk( x, y, tile );

	/*devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 16, y + 0, tile + 2 );

	devkit_SMS_addSprite( x + 0, y + 8, tile + 3 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 4 );
	devkit_SMS_addSprite( x + 16, y + 8, tile + 5 );

	devkit_SMS_addSprite( x + 0, y + 16, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 16, tile + 7 );
	devkit_SMS_addSprite( x + 16, y + 16, tile + 8 );

	devkit_SMS_addSprite( x + 0, y + 24, tile + 9 );
	devkit_SMS_addSprite( x + 8, y + 24, tile + 10 );
	devkit_SMS_addSprite( x + 16, y + 24, tile + 11 );*/
}