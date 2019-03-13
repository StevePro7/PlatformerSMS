#include "enemy_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"

void engine_enemyX_manager_load()
{
	struct_hack_object *ho = &global_hack_object;
	//engine_font_manager_draw_data( ho->hacker_enemy, 10, 10 );
}

void engine_enemyX_manager_draw()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char offX = 16;

	if( 0 == ho->hacker_enemy)
	{
		return;
	}
	if( ho->hacker_enemy > 0 )
	{
		//engine_sprite_manager_draw( 76, 80, 424 );
		engine_sprite_manager_draw( 236 - offX, 0, 424 );
	}
	if( ho->hacker_enemy > 1 )
	{
		//engine_sprite_manager_draw( 76 + 32, 80 - 32, 424 - 12 );
		engine_sprite_manager_draw( 236 - offX, 48, 424 - 12 );
	}
	if( ho->hacker_enemy > 2 )
	{
		//engine_sprite_manager_draw( 76 + 64, 80 - 64, 424 - 24 );
		engine_sprite_manager_draw( 236 - offX, 96, 424 - 24 );
	}
	if( ho->hacker_enemy > 3 )
	{
		//engine_sprite_manager_draw( 76 + 96, 80 + 32, 424 - 36 );
		engine_sprite_manager_draw( 236 - offX, 144, 424 - 36 );
	}
}

// Global variable.
struct_enemy_object global_enemy_object;
//struct_enemy_object global_enemy_object[ MAX_ENEMIES ];