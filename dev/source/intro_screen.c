#include "intro_screen.h"
#include "enum_manager.h"
#include "locale_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "game_manager.h"

void screen_intro_screen_load()
{
	struct_game_object *go = &global_game_object;
	unsigned char row;
	for( row = 0; row < 24; row++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, row );
	}

	engine_font_manager_draw_text( "INTRO", 6, 9 );
	engine_font_manager_draw_data( go->difficulty, 6, 10 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_hold_fire1();
	if( test )
	{
		*screen_type = screen_type_diff;
		return;
	}

	*screen_type = screen_type_intro;
}