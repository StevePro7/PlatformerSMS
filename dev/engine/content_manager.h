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
	SMS_loadPSGaidencompressedTiles( Player_Idle__tiles__psgcompr, SPRITE_TILES_OFFSET + 0 );
	SMS_loadPSGaidencompressedTiles( EnemyA_Idle_01__tiles__psgcompr, SPRITE_TILES_OFFSET + 8 );
	SMS_loadPSGaidencompressedTiles( EnemyB_Idle_01__tiles__psgcompr, SPRITE_TILES_OFFSET + 16 );
	SMS_loadPSGaidencompressedTiles( EnemyC_Idle_01__tiles__psgcompr, SPRITE_TILES_OFFSET + 24 );
	SMS_loadPSGaidencompressedTiles( EnemyD_Idle_01__tiles__psgcompr, SPRITE_TILES_OFFSET + 32 );
	SMS_loadSpritePalette( ( void * ) Sprites__palette__bin );
}

#endif//_CONTENT_MANAGER_H_