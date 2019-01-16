#ifndef _LOAD_SCREEN_H_
#define _LOAD_SCREEN_H_

void screen_load_screen_load()
{
	engine_font_manager_draw_text( "ADRIANA", 1, 5 );
}

void screen_load_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_load;
}

#endif//_LOAD_SCREEN_H_