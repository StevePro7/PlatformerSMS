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
#include "player_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "enemy_manager.h"
#include "state_manager.h"
//#include "stats_manager.h"
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
	engine_enemyX_manager_draw_guards();							// TODO override this method to draw outside "memo" box
	engine_memo_manager_draw_level( go->world_no, go->round_no );
	devkit_SMS_displayOn();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();							// TODO override this method to draw outside "memo" box
	//engine_player_manager_draw();									// TODO override this method to draw outside "memo" box
	engine_player_manager_hide( 4, 11 );
	delay = engine_delay_manager_update();
	if( delay )
	{
		*screen_type = screen_type_ready;
		//return;
	}

	*screen_type = screen_type_load;
}