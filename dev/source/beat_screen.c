#include "beat_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "text_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "stats_manager.h"
#include "game_manager.h"
#include "state_manager.h"

void screen_beat_screen_load()
{
	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE1, 9, 19 );
	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE2, 9, 20 );

	struct_game_object *go = &global_game_object;
	//struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;

	devkit_SMS_displayOff();
	engine_text_manager_cleat_all();

	// Load game content.
	engine_content_manager_load_guards();

	// Load sprite animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_move();
	engine_anim_manager_enemyX_load_idle();

	devkit_SMS_displayOn();


	engine_enemyX_manager_init();
	engine_level_manager_init_level();
	engine_level_manager_load_level( go->world_no, go->round_no, go->invincible, go->difficulty );

	devkit_SMS_displayOff();
	engine_level_manager_draw_level();
	devkit_SMS_displayOn();

	engine_state_manager_load();
	engine_enemyX_manager_load();


	// Reset player irrespective of new level or new life.
	engine_player_manager_load();
	engine_enemyX_manager_draw_guards();

	engine_font_manager_draw_text( "BEAT", 10, 0 );

	eo = &global_enemy_objects[ 0 ];
	/*engine_font_manager_draw_data( eo->leftX, 20, 0 );
	engine_font_manager_draw_data( eo->rghtX, 20, 1 );
	engine_font_manager_draw_data( eo->velX, 20, 2 );*/
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_move_fire2();

	if( test )
	{
		//engine_font_manager_draw_text( "SPLAT", 20, 12 );
		engine_enemyX_manager_update();
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();


	*screen_type = screen_type_beat;
}