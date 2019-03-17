#include "diff_screen.h"
#include "enum_manager.h"

void screen_diff_screen_load()
{
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_diff;
}