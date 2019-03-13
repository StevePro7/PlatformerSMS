#include "enemy_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"

// Global variable.
//struct_enemy_common global_enemy_common;
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

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
	//struct_enemy_object *eo;
	//unsigned char idx;

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