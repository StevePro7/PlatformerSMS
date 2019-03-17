#include "level_screen.h"
#include "enum_manager.h"

void screen_level_screen_load()
{
}

void screen_level_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_level;
}