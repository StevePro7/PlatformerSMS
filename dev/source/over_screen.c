#include "over_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "player_manager.h"
#include "input_manager.h"

void screen_over_screen_load()
{
	engine_font_manager_draw_text( "OVER!", 10, 9 );
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_hold_fire2();
	if( test )
	{
		*screen_type = screen_type_play;
		return;
	}

	engine_player_manager_draw();
	*screen_type = screen_type_over;
}