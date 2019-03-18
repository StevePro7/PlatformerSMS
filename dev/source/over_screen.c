#include "over_screen.h"
#include "global_manager.h"
#include "debug_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "state_manager.h"
#include "audio_manager.h"

void screen_over_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;

	// Load animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_anim_manager_enemyX_load_idle();

	engine_enemyX_manager_init();

	engine_level_manager_init_level();
	//engine_level_manager_load_index( 0, false, 0 );		//stevepro
	//engine_level_manager_load_index( ho->hacker_level );
	engine_level_manager_draw_level();

	engine_state_manager_load();
	engine_player_manager_load();
	engine_enemyX_manager_load();

	engine_font_manager_draw_text( "OVER", 10, 9 );

	//lo->enemyX_spot[ 0 ];
	//engine_font_manager_draw_data( lo->enemyX_spot[ 0 ], 10, 10 );
	//lo->enemys_spot[ 0 ] = 2;
	//engine_font_manager_draw_data( lo->enemyX_spot[ 0 ], 10, 11 );
}

void screen_over_screen_update( unsigned char *screen_type )
{
	/*unsigned char test;
	test = engine_input_manager_hold_fire2();
	if( test )
	{
		*screen_type = screen_type_play;
		return;
	}*/

	// Draw enemies first!
	engine_enemyX_manager_draw();
	engine_player_manager_draw();

	*screen_type = screen_type_over;
}