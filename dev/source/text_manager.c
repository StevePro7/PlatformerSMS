#include "text_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

#define CHEAT_Y		20

void engine_text_manager_clear_all()
{
	unsigned char cnt;
	for( cnt = 0; cnt < SCREEN_TILE_HIGH; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, cnt );
	}
}
void engine_text_manager_clear_three()
{
	unsigned char cnt;
	const unsigned char textY = 18;

	for( cnt = 0; cnt < 3; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, textY + cnt );
	}
}

void engine_text_manager_cheat_blank()
{
	/*unsigned char x;
	for( x = 0; x <= 4; x += 2 )
	{
		engine_font_manager_draw_text( LOCALE_SELECT_BLANK, SCREEN_TILE_LEFT + x, CHEAT_Y + 0 );
		engine_font_manager_draw_text( LOCALE_SELECT_BLANK, SCREEN_TILE_LEFT + x, CHEAT_Y + 1 );
	}*/

	engine_font_manager_draw_text( "      ", SCREEN_TILE_LEFT, CHEAT_Y + 1 );
}
void engine_text_manager_cheat_write()
{
	engine_font_manager_draw_text( LOCALE_PRESS_CHEAT, SCREEN_TILE_LEFT, CHEAT_Y + 1 );
	//engine_font_manager_draw_text( LOCALE_PRESS_CHEAT, SCREEN_TILE_LEFT, CHEAT_Y + 0 );
	//engine_font_manager_draw_text( LOCALE_PRESS_MODES, SCREEN_TILE_LEFT, CHEAT_Y + 1 );
}

void engine_text_manager_write_gems()
{
	engine_font_manager_draw_text( LOCALE_GEMS_TEXT, 28, 1 );
}