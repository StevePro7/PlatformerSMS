#include "render_manager.h"
#include "font_manager.h"
#include "hack_manager.h"

void source_game_manager_render()
{
	engine_font_manager_draw_char( 'X', 20, 5 );
	engine_font_manager_draw_data( hacker_debug, 20, 0 );
	engine_font_manager_draw_data( hacker_level, 20, 1 );
}