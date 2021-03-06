#ifndef _CONTENT_MANAGER_H_
#define _CONTENT_MANAGER_H_

#define BACK_TILES_OFFSET		0

void engine_content_manager_load_back_tiles()
{
	// Back tiles.
	SMS_loadPSGaidencompressedTiles( back_tiles__tiles__psgcompr, BACK_TILES_OFFSET );
	SMS_loadBGPalette( ( void * ) back_tiles__palette__bin );
}

void engine_content_manager_load_sprites()
{
	// Sprites.
	SMS_loadPSGaidencompressedTiles( Player_Idle__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_player ] );
	SMS_loadPSGaidencompressedTiles( EnemyA_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyA ] );
	SMS_loadPSGaidencompressedTiles( EnemyB_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyB ] );
	SMS_loadPSGaidencompressedTiles( EnemyC_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyC ] );
	SMS_loadPSGaidencompressedTiles( EnemyD_Idle_01__tiles__psgcompr, list_sprite_tile_offset[ sprite_type_enemyD ] );
	SMS_loadSpritePalette( ( void * ) Sprites__palette__bin );
}

#endif//_CONTENT_MANAGER_H_