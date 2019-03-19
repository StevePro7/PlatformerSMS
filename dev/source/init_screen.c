#include "init_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "game_manager.h"

void screen_init_screen_load()
{
	struct_game_object *go = &global_game_object;
	unsigned char level;

	level = go->world_no * MAX_ROUNDS + go->round_no + 1;

	engine_level_manager_init_level();
	engine_level_manager_load_level( go->world_no, go->round_no, go->invincible, go->difficulty );

	//engine_level_manager_load_index( ho->hacker_level );
	engine_level_manager_draw_level();

	engine_font_manager_draw_data( go->world_no + 1, 10, 10 );
	engine_font_manager_draw_data( go->round_no + 1, 10, 11 );
	engine_font_manager_draw_data( level, 10, 12 );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	unsigned char test;

	test = engine_input_manager_hold_fire2();
	if( !test )
	{
		*screen_type = screen_type_init;
		return;
	}

	
	
	*screen_type = screen_type_level;
}