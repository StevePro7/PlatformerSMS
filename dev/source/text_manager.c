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

void engine_text_manager_write_info( unsigned char round )
{
	unsigned char x, y = 5;
	x = 22;
	y = 4;

	if( 9 == round )
	{
		engine_font_manager_draw_text( "HINT: HOLD FIRE2 TO RESET", 2, y + 0 );
	}
	/*
	else if( 0 == round )
	{
		engine_font_manager_draw_text( "WELCOME HERO!", 2, y + 0 );
		engine_font_manager_draw_text( "HURRY TO THE EXIT!", 2, y + 1 );
		engine_font_manager_draw_text( "EXIT", 20, y + 20 );
	}
	else if( 1 == round )
	{
		engine_font_manager_draw_text( "JUMP ON BLOCKS", 2, y + 0 );
		engine_font_manager_draw_text( "WALK THROUGH PLATFORMS", 2, y + 1 );
	}
	else if( 2 == round )
	{
		engine_font_manager_draw_text(  "COLLECT THE GEMS", 2, y + 0 );
	}
	else if( 3 == round )
	{
		engine_font_manager_draw_text( "AVOID THE PITS", 2, y + 0 );
	}
	else if( 4 == round )
	{
		engine_font_manager_draw_text( "ENEMY DAVE", 2, y + 0 );
		engine_font_manager_draw_text( "SLOW PACED AND PAUSES", 2, y + 1 );
	}
	else if( 5 == round )
	{
		engine_font_manager_draw_text( "ENEMY ALEX", 2, y + 0 );
		engine_font_manager_draw_text( "MID-PACED AND CONSTANT", 2, y + 1 );
	}
	else if( 6 == round )
	{
		engine_font_manager_draw_text( "ENEMY MIKE", 2, y + 0 );
		engine_font_manager_draw_text( "MID-PACED BUT PAUSES", 2, y + 1 );
	}
	else if( 7 == round )
	{
		engine_font_manager_draw_text( "ENEMY EDDIE", 2, y + 0 );
		engine_font_manager_draw_text( "FAST PACED AND CONSTANT", 2, y + 1 );
	}
	else if( 8 == round )
	{
		//engine_font_manager_draw_text( "ENEMY EDDIE", 2, y + 0 );
		engine_font_manager_draw_text( "GUARDS DO NOT MOVE", 2, y + 1 );
	}
	*/
}