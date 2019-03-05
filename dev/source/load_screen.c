#include "load_screen.h"
#include "global_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "state_manager.h"

#define ENEMYA_TILE		256
#define ENEMYB_TILE		292
#define ENEMYC_TILE		436

void screen_load_screen_load()
{
	engine_debug_manager_draw_grid();		// TODO remove this!

	//engine_level_manager_load_index( 0 );
	engine_level_manager_load_levelX();

	engine_state_manager_load();
	//engine_player_manager_load();

	engine_anim_manager_enemyA_load( 0, ENEMYA_TILE );
	engine_anim_manager_enemyB_load( 0, ENEMYB_TILE );
	engine_anim_manager_enemyC_load( 0, ENEMYC_TILE );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	engine_anim_manager_draw( 64, 0, ENEMYA_TILE );
	engine_anim_manager_draw( 64, 48, ENEMYB_TILE );
	engine_anim_manager_draw( 64, 96, ENEMYC_TILE );

	*screen_type = screen_type_load;
}