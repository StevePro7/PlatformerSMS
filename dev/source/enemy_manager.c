#include "enemy_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"

void engine_enemyX_manager_load()
{
}

void engine_enemyX_manager_draw()
{
	engine_sprite_manager_draw( 76, 80, 424 );
	engine_sprite_manager_draw( 76 + 32, 80 - 32, 424 - 12 );
	engine_sprite_manager_draw( 76 + 64, 80 - 64, 424 - 24 );
	engine_sprite_manager_draw( 76 + 96, 80 + 32, 424 - 36 );
}

// Global variable.
struct_enemy_object global_enemy_object;
//struct_enemy_object global_enemy_object[ MAX_ENEMIES ];