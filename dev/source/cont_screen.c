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
	// Clear middle section
	// CONTINUE GAME?
	// >>YES    >>NO
	//engine_font_manager_draw_text( "CONT SCREEN", 10, 10 );
	//engine_delay_manager_load( 100 );

	engine_memo_manager_draw( 8, 18 );		// cont
	engine_font_manager_draw_text( LOCALE_CONT_MESSAGE, 10, MEMO_TEXT_TOP );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, 10, MEMO_TEXT_BOT );
	//engine_font_manager_draw_text( LOCALE_CONT_YES, 12, MEMO_TEXT_BOT );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROW, 19, MEMO_TEXT_BOT );
	//engine_font_manager_draw_text( LOCALE_CONT_NO, 21, MEMO_TEXT_BOT );
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