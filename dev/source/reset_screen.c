#include "reset_screen.h"
#include "enum_manager.h"

void screen_reset_screen_load()
{
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_reset;
}