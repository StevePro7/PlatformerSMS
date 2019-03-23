#include "beat_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "text_manager.h"
#include "memo_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include <stdlib.h>

void screen_beat_screen_load()
{
	//devkit_SMS_displayOff();
	//engine_text_manager_clear_all();
	engine_memo_manager_draw_beat();
	//devkit_SMS_displayOn();
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	const unsigned char leftX = 3;
	const unsigned char rghtX = 12;

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );
	engine_player_manager_hide( leftX, rghtX );

	*screen_type = screen_type_beat;
}