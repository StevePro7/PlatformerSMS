#include "init_screen.h"
#include "global_manager.h"
#include "content_manager.h"
#include "anim_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_init_screen_load()
{
	// Load game content.
	engine_content_manager_load_guards();

	// Load sprite animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_anim_manager_enemyX_load_idle();
}

void screen_init_screen_update( unsigned char *screen_type )
{
	//unsigned char test;

	/*test = engine_input_manager_hold_fire2();
	if( !test )
	{
		*screen_type = screen_type_init;
		return;
	}*/

	*screen_type = screen_type_init;
	//*screen_type = screen_type_level;
}