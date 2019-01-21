#include "main.h"

enum_screen_type curr_screen_type, next_screen_type;

void( *load_method[ MAX_STATES ] )( );
void( *update_method[ MAX_STATES ] )( enum_screen_type *screen_type );

void custom_initialize();

void main(void)
{
	/*bool test = false;
	int i = 0;*/

	SMS_init();
	SMS_displayOff();
	SMS_setSpriteMode( SPRITEMODE_NORMAL );
	SMS_useFirstHalfTilesforSprites( true );
	//SMS_VDPturnOnFeature( VDPFEATURE_HIDEFIRSTCOL );

	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_sprites();
	engine_content_manager_load_back_tiles();

	//engine_font_manager_draw_text("STEVEPRO", 1, 1);
	//engine_font_manager_draw_char('D', 1, 0);

	//load_room( level0201_txt );
	//load_room( level0301_txt );
	//load_room( level0200_txt, 2 );
	//engine_font_manager_draw_data( i, 20, 0 );

	custom_initialize();
	curr_screen_type = screen_type_none;
	next_screen_type = screen_type_load;

	SMS_displayOn();
	for (;;)
	{
		if( curr_screen_type != next_screen_type )
		{
			curr_screen_type = next_screen_type;
			load_method[ curr_screen_type ]();
		}


		SMS_initSprites();
		engine_input_manager_update();
		//test = engine_input_manager_hold_up();
		/*test = engine_input_manager_move_up();
		if( test )
		{
			i++;
			engine_font_manager_draw_data( i, 20, 0 );
		}*/
		//engine_sprite_manager_draw_player( 16 * 1 + GAME_X_OFFSET, 144 );
		//engine_sprite_manager_draw_enemyA( 16 * 4 + GAME_X_OFFSET, 144 );
		/*engine_sprite_manager_draw_enemyB( 16 * 7 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyC( 16 * 10 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyD( 16 * 7 + GAME_X_OFFSET, 48 );*/

		//screen_none_screen_update();
		update_method[ curr_screen_type ]( &next_screen_type );

		SMS_finalizeSprites();
		SMS_waitForVBlank();
		SMS_copySpritestoSAT();
	}
}

void custom_initialize()
{
	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!");
#endif
