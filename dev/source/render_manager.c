#include "render_manager.h"
#include "hack_manager.h"
#include "font_manager.h"

void source_game_manager_render()
{
	struct_hack_object *ho = &hack_object;
	engine_font_manager_draw_data( 69, 20, 9 );
	engine_font_manager_draw_data( ho->hacker_debug, 20, 17 );
	engine_font_manager_draw_data( ho->hacker_level, 22, 18 );
}