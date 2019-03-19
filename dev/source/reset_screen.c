#include "reset_screen.h"
#include "enum_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "game_manager.h"

void screen_reset_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

	engine_font_manager_draw_text( "RESET SCREEN", 10, 0 );
	engine_font_manager_draw_data( ho->hack_difficulty, 20, 20 );
	engine_font_manager_draw_data( go->difficulty, 20, 21 );
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_reset;
}