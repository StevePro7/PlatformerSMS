#include "main.h"

// Global variables.
//bool global_pause;
//enum_screen_type curr_screen_type, next_screen_type;

//void( *load_method[ MAX_SCREEENS ] )( );
//void( *update_method[ MAX_SCREEENS ] )( enum_screen_type *screen_type );

//void custom_initialize();
void draw_grid();

void main(void)
{
	bool test = false;
	int i = 0;

	engine_asm_manager_clear_VRAM();

	//engine_game_manager_init();
	devkit_SMS_init();
	devkit_SMS_displayOff();

	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_useFirstHalfTilesforSprites_True();						// true changes tile color in Tile Viewer
	//devkit_SMS_VDPturnOnFeature( devkit_VDPFEATURE_HIDEFIRSTCOL() );	// TODO remember to uncomment this...!


	//source_game_manager_common();
	//source_game_manager_render();

	//engine_game_manager_common();
	//engine_game_manager_render();

	engine_content_manager_load_sprites();
	engine_content_manager_load_back_tiles();

	draw_grid();
	engine_font_manager_draw_data( i, 10, 0 );
	//engine_font_manager_draw_text( "SUZANNE", 0, 0 );
	//engine_font_manager_draw_text( "!@#$%^&*()", 20, 0 );
	//engine_font_manager_draw_data( 7000, 10, 1 );
	//engine_font_manager_draw_data_ZERO( 8000, 10, 2 );

	engine_tile_manager_draw_tile( tile_type_blockerA, 6, 14 );
	engine_tile_manager_draw_tile( tile_type_blockerB, 8, 14 );
	engine_tile_manager_draw_tile( tile_type_blockerC, 10, 14 );
	
	
	/*custom_initialize();
	curr_screen_type = screen_type_none;
	next_screen_type = screen_type_load;*/
	//next_screen_type = screen_type_test;

	//SMS_setSpritePaletteColor( 0, RGB( 3, 3, 2 ) );
	
	devkit_SMS_displayOn();
	for (;;)
	{
		/*if( curr_screen_type != next_screen_type )
		{
			curr_screen_type = next_screen_type;
			load_method[ curr_screen_type ]();
		}*/


		devkit_SMS_initSprites();
		engine_input_manager_update();
		test = engine_input_manager_hold_fire2();
		//test = engine_input_manager_move_fire2();
		if( test )
		{
			i++;
			engine_font_manager_draw_data( i, 10, 0 );
		}
		engine_sprite_manager_draw( 64, 80, sprite_type_player );
		//engine_sprite_manager_draw_player( 16 * 1 + GAME_X_OFFSET, 144 );
		//engine_sprite_manager_draw_enemyA( 16 * 4 + GAME_X_OFFSET, 144 );
		/*engine_sprite_manager_draw_enemyB( 16 * 7 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyC( 16 * 10 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyD( 16 * 7 + GAME_X_OFFSET, 48 );*/

		//screen_none_screen_update();
		//update_method[ curr_screen_type ]( &next_screen_type );

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();
		devkit_SMS_copySpritestoSAT();
	}
}

void draw_grid()
{
	unsigned char x, y;
	for( y = 0; y < 24; y+=2)
	{
		for( x = 0; x < 32; x+=2 )
		{
			engine_tile_manager_draw_tile( tile_type_gridline, x, y );
		}
	}
}

//void custom_initialize()
//{
//	// Set load methods.
//	load_method[ screen_type_none ] = screen_none_screen_load;
//	load_method[ screen_type_test ] = screen_test_screen_load;
//	load_method[ screen_type_init ] = screen_init_screen_load;
//	load_method[ screen_type_load ] = screen_load_screen_load;
//	load_method[ screen_type_play ] = screen_play_screen_load;
//	load_method[ screen_type_func ] = screen_func_screen_load;
//	load_method[ screen_type_splash ] = screen_splash_screen_load;
//
//	// Set update methods.
//	update_method[ screen_type_none ] = screen_none_screen_update;
//	update_method[ screen_type_test ] = screen_test_screen_update;
//	update_method[ screen_type_init ] = screen_init_screen_update;
//	update_method[ screen_type_load ] = screen_load_screen_update;
//	update_method[ screen_type_play ] = screen_play_screen_update;
//	update_method[ screen_type_func ] = screen_func_screen_update;
//	update_method[ screen_type_splash ] = screen_splash_screen_update;
//
//	// Initialize hack manager.
//	engine_hack_manager_init();
//	engine_hack_manager_invert();
//}

//#ifdef _CONSOLE
//#else
//	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
//	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!");
//#endif
