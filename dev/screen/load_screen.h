#ifndef _LOAD_SCREEN_H_
#define _LOAD_SCREEN_H_

void screen_load_screen_load()
{
	engine_level_manager_load_level( level0201_txt );

	engine_level_manager_draw_level();
}

void screen_load_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_load;
}

#endif//_LOAD_SCREEN_H_