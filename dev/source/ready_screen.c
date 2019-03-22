#include "ready_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "player_manager.h"
#include "level_manager.h"
#include "enemy_manager.h"
//#include "audio_manager.h"

void screen_ready_screen_load()
{
	// Reset player irrespective of new level or new life.
	engine_player_manager_load();

	engine_level_manager_draw_section();
	engine_enemyX_manager_draw_guards();

	// TODO draw middle section of level again
	// because may be over written with CONTINEUE
	// Also, re-draw the hearts for lives on LHS


	// TODO wire up different game play music...
	//engine_audio_manager_start_music();
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	*screen_type = screen_type_play;
}