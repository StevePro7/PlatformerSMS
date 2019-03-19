#include "init_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "content_manager.h"
#include "anim_manager.h"
#include "enum_manager.h"
#include "text_manager.h"

void screen_init_screen_load()
{
	devkit_SMS_displayOff();
	engine_text_manager_cleat_all();

	// Load game content.
	engine_content_manager_load_guards();

	// Load sprite animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_anim_manager_enemyX_load_idle();

	devkit_SMS_displayOn();
}

void screen_init_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_load;
}