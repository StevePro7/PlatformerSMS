#include "load_screen.h"
#include "_sms_manager.h"
//#include "global_manager.h"
//#include "hack_manager.h"
#include "enum_manager.h"
//#include "font_manager.h"
//#include "tile_manager.h"
#include "memo_manager.h"
#include "level_manager.h"
//#include "anim_manager.h"
//#include "player_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "enemy_manager.h"
#include "state_manager.h"
//#include "stats_manager.h"
#include "game_manager.h"

#define LOAD_SCREEN_DELAY		250

void screen_load_screen_load()
{
	struct_game_object *go = &global_game_object;

	engine_delay_manager_load( LOAD_SCREEN_DELAY );
	engine_enemyX_manager_init();
	engine_level_manager_init_level();

	engine_level_manager_load_level( go->world_no, go->round_no, go->invincible, go->difficulty );

	devkit_SMS_displayOff();
	engine_level_manager_draw_level();
	engine_memo_manager_draw_level( go->world_no, go->round_no );
	devkit_SMS_displayOn();

	engine_state_manager_load();
	engine_enemyX_manager_load();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	//unsigned char input;

	delay = engine_delay_manager_update();
	//input = engine_input_manager_hold_fire1();

	//if( delay || input )
	if( delay )
	{
		*screen_type = screen_type_ready;
		return;
	}

	*screen_type = screen_type_load;
}