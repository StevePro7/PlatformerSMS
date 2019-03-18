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
	unsigned char line;
	unsigned char level;

	for( line = 0; line < 24; line++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, line );
	}

	level = go->world_no * MAX_ROUNDS + go->round_no;

	engine_level_manager_init_level();
	//engine_level_manager_load_index( level, go->invincible, go->difficulty );
	engine_level_manager_load_steve( go->world_no, go->round_no, go->invincible, go->difficulty );

	//engine_level_manager_load_index( ho->hacker_level );
	engine_level_manager_draw_level();

	engine_font_manager_draw_data( level, 10, 10 );
	engine_font_manager_draw_data( go->invincible, 10, 11 );
	engine_font_manager_draw_data( go->difficulty, 10, 12 );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	//unsigned char line;

	/*for( line = 0; line < 24; line++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, line );
	}*/

	*screen_type = screen_type_init;
}