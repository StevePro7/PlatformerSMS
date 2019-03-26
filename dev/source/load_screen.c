#include "load_screen.h"
#include "_sms_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "state_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define LOAD_SCREEN_DELAY		150

void screen_load_screen_load()
{
	struct_game_object *go = &global_game_object;
	unsigned char invincible;

	engine_audio_manager_music_stop();
	engine_delay_manager_load( LOAD_SCREEN_DELAY );
	engine_enemyX_manager_init();
	engine_level_manager_init_level();

	invincible = go->invincible || go->localcheat;
	engine_level_manager_load_level( go->world_no, go->round_no, invincible, go->difficulty );
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
	engine_score_manager_draw_score( 31, 2 );
	engine_score_manager_draw_lives();
	devkit_SMS_displayOn();

	// Reset gem count at each level.
	engine_score_manager_reset_gems();
	//engine_audio_manager_music_game( 0 );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 2 ] = { 0, 0 };
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	// Prompt to move to enter level quicker...
	test[ 0 ] = engine_input_manager_move_left();
	test[ 1 ] = engine_input_manager_move_right();

	delay = engine_delay_manager_update();
	if( test[ 0 ] || test[ 1 ] || delay )
	{
		//engine_font_manager_draw_text( "LOAD", 20, 2 );
		engine_audio_manager_music_game( 0 );
		*screen_type = screen_type_ready;
		return;
	}

	*screen_type = screen_type_load;
}