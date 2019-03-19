#include "dead_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "input_manager.h"

void screen_dead_screen_load()
{
	engine_font_manager_draw_text( "DEAD!", 6, 9 );
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_hold_fire2();
	if( test )
	{
		engine_font_manager_draw_text( "     ", 6, 9 );
		*screen_type = screen_type_ready;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();
	*screen_type = screen_type_dead;
}