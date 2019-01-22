#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

void screen_play_screen_load()
{
	unsigned char vdp = SMS_VDPType();
	unsigned char t1 = VDP_PAL == vdp;
	unsigned char t2 = VDP_NTSC == vdp;

	//engine_font_manager_draw_text( "PLAY SCREEN", 0, 0 );
	engine_font_manager_draw_data( t1, 20, 2 );
	engine_font_manager_draw_data( t2, 20, 3 );

	engine_player_manager_load();
}

void screen_play_screen_update( enum_screen_type *screen_type )
{
	engine_player_manager_update();
	engine_player_manager_draw();

	*screen_type = screen_type_play;
}

#endif//_PLAY_SCREEN_H_