#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

void screen_play_screen_load()
{
	engine_font_manager_draw_text( "PLAY SCREEN", 0, 0 );

	engine_player_manager_load();
}

void screen_play_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_play;
}

#endif//_PLAY_SCREEN_H_