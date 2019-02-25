#include "play_screen.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "player_manager.h"

void screen_play_screen_load()
{
	engine_level_manager_load_levelX();
	engine_player_manager_load();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	engine_player_manager_update();
	*screen_type = screen_type_play;
}