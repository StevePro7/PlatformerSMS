#include "ready_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"

void screen_ready_screen_load()
{
	engine_font_manager_draw_text( "READY", 10, 10 );

	// Reset player irrespective of new level or new life.
	engine_player_manager_load();

	engine_enemyX_manager_draw_guards();
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	engine_enemyX_manager_draw_enemys();
	*screen_type = screen_type_ready;
}