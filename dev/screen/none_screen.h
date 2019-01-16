#ifndef _NONE_SCREEN_H_
#define _NONE_SCREEN_H_

void screen_none_screen_load()
{
}

void screen_none_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_none;
}

#endif//_NONE_SCREEN_H_