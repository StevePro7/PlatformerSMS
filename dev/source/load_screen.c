#include "load_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "text_manager.h"
#include "memo_manager.h"
#include "level_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "state_manager.h"
#include "game_manager.h"

#define LOAD_SCREEN_DELAY		100

void screen_load_screen_load()
{
	struct_game_object *go = &global_game_object;

	engine_delay_manager_load( LOAD_SCREEN_DELAY );
	engine_enemyX_manager_init();
	engine_level_manager_init_level();

	engine_level_manager_load_level( go->world_no, go->round_no, go->invincible, go->difficulty );
	engine_state_manager_load();
	engine_player_manager_load();
	engine_enemyX_manager_load();

	devkit_SMS_displayOff();
	engine_level_manager_draw_level();
	engine_enemyX_manager_draw_guards();
	engine_memo_manager_draw_title();
	engine_memo_manager_draw_level( go->world_no, go->round_no );

	// Display game stats.
	engine_game_manager_draw();
	engine_text_manager_write_gems();
	engine_score_manager_draw_score( 31, 1 );
	//engine_score_manager_draw_heart();
	engine_score_manager_draw_lives();
	devkit_SMS_displayOn();

	// Reset gem count at each level.
	engine_score_manager_reset_gems();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 2 ] = { 0, 0 };
	unsigned char delay;

	//const unsigned char leftX = 4;
	//const unsigned char rghtX = 11;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();
	//engine_enemyX_manager_hide_enemys( leftX , rghtX );
	//engine_player_manager_hide( leftX, rghtX );


	// Prompt to move to enter level quicker...
	test[ 0 ] = engine_input_manager_hold_left();
	test[ 1 ] = engine_input_manager_hold_right();

	delay = engine_delay_manager_update();
	if( test[ 0 ] || test[ 1 ] || delay )
	{
		*screen_type = screen_type_ready;
		return;
	}

	*screen_type = screen_type_load;
}