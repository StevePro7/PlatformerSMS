#include "cont_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include <stdlib.h>

void screen_cont_screen_load()
{
		engine_memo_manager_draw_cont();
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	//unsigned char test = engine_delay_manager_update();
	//engine_font_manager_draw_data( test, 10, 15 );

	/*if( test )
	{
		*screen_type = screen_type_reset;
		return;
	}*/

	// if input_manager( fire1 ) then
	// Clear middle section
	// Draw level mid section
	// goto Ready screen
	*screen_type = screen_type_cont;
}