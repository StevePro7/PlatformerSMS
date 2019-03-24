#include "content_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "..\banks\bank2.h"
#include "..\banks\bank3.h"
#include "..\gfx.h"

#define BACK_TILES_OFFSET		0
#define MISC_TILES_OFFSET		128

void engine_content_manager_load_back_tiles()
{
	// Back tiles.
	devkit_SMS_loadPSGaidencompressedTiles( back_tiles__tiles__psgcompr, BACK_TILES_OFFSET );
	devkit_SMS_loadBGPalette( ( void * ) back_tiles__palette__bin );
}

void engine_content_manager_load_sprites()
{
	// Sprites.
	/*unsigned char index;
	unsigned char count = 16;
	unsigned char offset = 8;
	for( index = 0; index < count; index++ )
	{
		devkit_SMS_loadPSGaidencompressedTiles( Player_Idle__tiles__psgcompr, index * offset + SPRITE_TILES_OFFSET );
	}*/

	//devkit_SMS_loadPSGaidencompressedTiles( Player_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_player ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyA_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyA ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyB_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyB ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyC_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyC ] );
	//devkit_SMS_loadPSGaidencompressedTiles( EnemyD_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyD ] );

	devkit_SMS_mapROMBank( sprites__palette__bin_bank );
	devkit_SMS_loadSpritePalette( ( void * ) sprites__palette__bin );
}

void engine_content_manager_load_splash()
{
	devkit_SMS_mapROMBank( splash__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( splash__tiles__psgcompr, MISC_TILES_OFFSET );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) splash__tilemap__stmcompr );
}

void engine_content_manager_load_title()
{
	// TODO confirm which is the final title - I believe Title6 is more theme aligned...
	//devkit_SMS_mapROMBank( title6__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( title6__tiles__psgcompr, MISC_TILES_OFFSET );
	//devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) title6__tilemap__stmcompr );

	devkit_SMS_mapROMBank( title8__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( title8__tiles__psgcompr, MISC_TILES_OFFSET );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) title8__tilemap__stmcompr );
}

void engine_content_manager_load_guards()
{
	// Enemy tiles.
	devkit_SMS_mapROMBank( guardA_idle__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( guardA_idle__tiles__psgcompr, MISC_TILES_OFFSET + 0 * GUARDS_TILES_NUMBER );
	devkit_SMS_loadPSGaidencompressedTiles( guardB_idle__tiles__psgcompr, MISC_TILES_OFFSET + 1 * GUARDS_TILES_NUMBER );
	devkit_SMS_loadPSGaidencompressedTiles( guardC_idle__tiles__psgcompr, MISC_TILES_OFFSET + 2 * GUARDS_TILES_NUMBER );
	devkit_SMS_loadPSGaidencompressedTiles( guardD_idle__tiles__psgcompr, MISC_TILES_OFFSET + 3 * GUARDS_TILES_NUMBER );
}