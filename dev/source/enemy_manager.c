#include "enemy_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"

// Global variable.
struct_enemy_master global_enemy_master;
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

#define DRAW_OFFSET_X	-4
static void get_draw_position( unsigned char idx );

void engine_enemyX_manager_init()
{
	struct_enemy_object *eo;
	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->spotX = 0;
		eo->spotY = 0;
	}
}

void engine_enemyX_manager_load()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;

	// Calculate player starting spot based on level.
	int rectX, rectB;
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		//engine_font_manager_draw_data( eo->spotX, 10, 14 );
		//engine_font_manager_draw_data( eo->spotY, 10, 15 );

		eo->posnX = 0;	eo->posnY = 0;
		rectX = eo->spotX * TILE_WIDE;
		rectB = eo->spotY * TILE_HIGH + TILE_HIGH;
		eo->posnX = rectX + TILE_WIDE / 2;
		eo->posnY = rectB;

		//engine_font_manager_draw_data( eo->posnX, 10, 14 );
		//engine_font_manager_draw_data( eo->posnY, 10, 15 );

		get_draw_position( idx );

		//engine_font_manager_draw_data( eo->drawX, 10, 16 );
		//engine_font_manager_draw_data( eo->drawY, 10, 17 );
	}

	// Calculate player starting spot based on level.
	//int rectX, rectB;
	//for( idx = 0; idx < MAX_ENEMIES; idx++ )
	//{
	//	eo = &global_enemy_objects[ idx ];

	//	engine_font_manager_draw_data( eo->spotX, 10, 14 );
	//	engine_font_manager_draw_data( eo->spotY, 10, 15 );
	//	//engine_font_manager_draw_data( eo->drawX, 10, 6 );
	//	//engine_font_manager_draw_data( eo->drawY, 10, 7 );

		/*eo->posnX = 0;	eo->posnY = 0;
		rectX = eo->spotX * TILE_WIDE;
		rectB = eo->spotY * TILE_HIGH + TILE_HIGH;
		eo->posnX = rectX + TILE_WIDE / 2;
		eo->posnY = rectB;*/
		//get_draw_position( idx );
	//}

	
	//// Calculate enemyX starting spot based on level.
	//int rectX, rectB;
	//eo->posnX = 0;	eo->posnY = 0;
	//rectX = eo->spotX * TILE_WIDE;
	//rectB = eo->spotY * TILE_HIGH + TILE_HIGH;
	//eo->posnX = rectX + TILE_WIDE / 2;
	//eo->posnY = rectB;
}

void engine_enemyX_manager_draw()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	unsigned int tile = 388;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		engine_sprite_manager_draw( eo->drawX, eo->drawY, tile );
	}

	//struct_hack_object *ho = &global_hack_object;
	//unsigned char offX = 16;

	//if( 0 == ho->hacker_enemy)
	//{
	//	return;
	//}
	//if( ho->hacker_enemy > 0 )
	//{
	//	//engine_sprite_manager_draw( 76, 80, 424 );
	//	engine_sprite_manager_draw( 236 - offX, 0, 424 );
	//}
	//if( ho->hacker_enemy > 1 )
	//{
	//	//engine_sprite_manager_draw( 76 + 32, 80 - 32, 424 - 12 );
	//	engine_sprite_manager_draw( 236 - offX, 48, 424 - 12 );
	//}
	//if( ho->hacker_enemy > 2 )
	//{
	//	//engine_sprite_manager_draw( 76 + 64, 80 - 64, 424 - 24 );
	//	engine_sprite_manager_draw( 236 - offX, 96, 424 - 24 );
	//}
	//if( ho->hacker_enemy > 3 )
	//{
	//	//engine_sprite_manager_draw( 76 + 96, 80 + 32, 424 - 36 );
	//	engine_sprite_manager_draw( 236 - offX, 144, 424 - 36 );
	//}
}

// Global variable.
//struct_enemy_object global_enemy_object;
//struct_enemy_object global_enemy_object[ MAX_ENEMIES ];

static void get_draw_position( unsigned char idx )
{
	struct_enemy_object *eo = &global_enemy_objects[ idx ];

	int halfTileSizeX = TILE_WIDE / 2;
	int twiceTileSizeY = 2 * TILE_HIGH;

	eo->drawX = eo->posnX - halfTileSizeX + DRAW_OFFSET_X;
	eo->drawY = eo->posnY - twiceTileSizeY;
}