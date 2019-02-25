#include "play_screen.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "render_manager.h"

void screen_play_screen_load()
{
	struct_hack_object *ho = &hack_object;
	engine_font_manager_draw_data( ho->hacker_debug, 20, 7 );
	engine_font_manager_draw_data( ho->hacker_level, 22, 8 );

	//source_game_manager_render();
	//engine_level_manager_load_levelX();
	//engine_player_manager_load();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	engine_player_manager_update();
	*screen_type = screen_type_play;
}