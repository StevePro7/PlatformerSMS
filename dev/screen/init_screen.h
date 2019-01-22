#ifndef _INIT_SCREEN_H_
#define _INIT_SCREEN_H_

void screen_init_screen_load()
{
}

void screen_init_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_init;
}

#endif//_INIT_SCREEN_H_