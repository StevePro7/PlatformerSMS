#include "content_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "..\gfx.h"

#define BACK_TILES_OFFSET		0

void engine_content_manager_load_back_tiles()
{
	// Back tiles.
	devkit_SMS_loadPSGaidencompressedTiles( back_tiles__tiles__psgcompr, BACK_TILES_OFFSET );
	devkit_SMS_loadBGPalette( ( void * ) back_tiles__palette__bin );
}

void engine_content_manager_load_sprites()
{
	// Sprites.
	unsigned char index;
	unsigned char count = 16;
	unsigned char offset = 8;
	for( index = 0; index < count; index++ )
	{
		devkit_SMS_loadPSGaidencompressedTiles( EnemyD_Idle_01__tiles__psgcompr, index * offset + SPRITE_TILES_OFFSET );
	}

	//devkit_SMS_loadPSGaidencompressedTiles( Player_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_player ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyA_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyA ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyB_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyB ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyC_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyC ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyD_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyD ] );
	devkit_SMS_loadSpritePalette( ( void * ) Sprites__palette__bin );
}