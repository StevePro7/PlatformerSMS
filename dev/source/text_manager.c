#include "tile_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

void engine_text_manager_cleat_all()
{
	unsigned char cnt;
	for( cnt = 0; cnt < SCREEN_TILE_HIGH; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, cnt );
	}
}

void engine_text_manager_cleat_three()
{
	unsigned char cnt;
	unsigned char textY = 18;

	for( cnt = 0; cnt < 3; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, textY + cnt );
	}
}