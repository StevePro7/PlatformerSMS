#include "load_screen.h"
#include "enum_manager.h"

void screen_load_screen_load()
{
}

void screen_load_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_load;
}