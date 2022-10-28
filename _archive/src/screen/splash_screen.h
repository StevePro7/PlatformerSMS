#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

void screen_splash_screen_load()
{
	engine_font_manager_draw_text( "STEVEPRO", 1, 5 );
}

void screen_splash_screen_update( enum_screen_type *screen_type )
{
	engine_font_manager_draw_text( "STUDIOS", 20, 17 );
	*screen_type = screen_type_splash;
}

#endif//_SPLASH_SCREEN_H_