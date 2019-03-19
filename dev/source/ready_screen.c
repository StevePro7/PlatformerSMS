#include "ready_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"

void screen_ready_screen_load()
{
	// Reset player irrespective of new level or new life.
	engine_player_manager_load();

	devkit_SMS_displayOff();
	engine_enemyX_manager_draw_guards();

	// TODO draw middle section of level again
	// because may be over written with CONTINEUE
	// Also, re-draw the hearts for lives on LHS

	devkit_SMS_displayOn();
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	//*screen_type = screen_type_play;
	*screen_type = screen_type_over;
}