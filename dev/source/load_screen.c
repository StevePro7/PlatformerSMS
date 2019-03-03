#include "load_screen.h"
#include "global_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "state_manager.h"

void screen_load_screen_load()
{
	//engine_debug_manager_draw_grid();		// TODO remove this!

	engine_level_manager_load_index( 0 );
	//engine_level_manager_draw_level();

	engine_state_manager_load();
	engine_player_manager_load();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_load;
}