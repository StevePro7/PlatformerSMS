#include "main.h"

enum_screen_type enum_curr_screen_type, enum_next_screen_type;

void main(void)
{
	bool test = false;
	int i = 0;

	SMS_init();
	SMS_displayOff();
	SMS_setSpriteMode( SPRITEMODE_NORMAL );
	SMS_useFirstHalfTilesforSprites( true );
	SMS_VDPturnOnFeature( VDPFEATURE_HIDEFIRSTCOL );

	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_sprites();
	engine_content_manager_load_back_tiles();

	//engine_font_manager_draw_text("STEVEPRO", 1, 1);
	//engine_font_manager_draw_char('D', 1, 0);

	//engine_tile_manager_draw_tile(0, 4, 2);
	/*engine_tile_manager_draw_tile(blockerD, 4, 2);
	engine_tile_manager_draw_tile(blockerE, 6, 2);
	engine_tile_manager_draw_tile(passable, 8, 2);
	engine_tile_manager_draw_tile(passable, 10, 2);
	engine_tile_manager_draw_tile(exitgame, 12, 2);
	engine_tile_manager_draw_tile(blockerG, 14, 2);
	engine_tile_manager_draw_tile(blockerG, 16, 2);
	engine_tile_manager_draw_tile(gemscore, 16, 0);*/

	//engine_content_manager_load();

	//load_room( level0201_txt );
	//load_room( level0301_txt );
	load_room( level0200_txt, 2 );
	engine_font_manager_draw_data( i, 20, 0 );

	SMS_displayOn();
	for (;;)
	{
		SMS_initSprites();
		
		engine_input_manager_update();
		test = engine_input_manager_hold_up();
		//test = engine_input_manager_move_down();
		if( test )
		{
			i++;
			engine_font_manager_draw_data( i, 20, 0 );
		}
		engine_sprite_manager_draw_player( 16 * 1 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyA( 16 * 4 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyB( 16 * 7 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyC( 16 * 10 + GAME_X_OFFSET, 144 );
		engine_sprite_manager_draw_enemyD( 16 * 7 + GAME_X_OFFSET, 48 );

		SMS_finalizeSprites();
		SMS_waitForVBlank();
		SMS_copySpritestoSAT();
	}
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!");
#endif
