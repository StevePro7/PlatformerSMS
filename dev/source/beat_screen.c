#include "beat_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_beat_screen_load()
{
	engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE1, 9, 19 );
	engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE2, 9, 20 );
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_beat;
}