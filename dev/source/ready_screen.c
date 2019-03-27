#include "ready_screen.h"
#include "_sms_manager.h"
#include "_snd_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"

#define READY_SCREEN_DELAY		75
//static unsigned char status;

void screen_ready_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;

	engine_delay_manager_load( READY_SCREEN_DELAY );

	// If player killed by enemy then reset enemy killer.
	if( INVALID_INDEX != po->kill_idx )
	{
		eo = &global_enemy_objects[ po->kill_idx ];
		if( action_type_chase == eo->action_type )
		{
			eo->posnX = eo->startX;
		}
	}

	// Reset player irrespective of new level or new life.
	// Reset killer index unconditionally on player load.
	engine_player_manager_load();

	engine_level_manager_draw_section();
//	engine_enemyX_manager_draw_guards();
	engine_score_manager_draw_lives();

	// TODO re-draw the hearts for lives on LHS
	// TODO wire up different game play music...
	//engine_audio_manager_start_music();
	//engine_audio_manager_music_game( 0 );

	//status = PSGGetStatus();
	//engine_font_manager_draw_data( status, 20, 2 );
	/*if( 0 == status )
	{
		engine_audio_manager_music_game( 0 );
	}

	engine_audio_manager_music_resume();*/

	//engine_font_manager_draw_text( "READY", 20, 3 );
}

void screen_ready_screen_update( unsigned char *screen_type )
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
		// If navigate from load screen then play music.
		//if( 0 == status )
		//{
		//	engine_audio_manager_music_game( 0 );
		//}
		//else
		//{
		//	// Otherwise navigate from dead, cont, reset and resume...
		//	engine_audio_manager_music_resume();
		//}
		

		engine_audio_manager_music_resume();

		*screen_type = screen_type_play;
		return;
	}

	*screen_type = screen_type_ready;
}