#include "main.h"

void main(void)
{
	SMS_init();
	SMS_displayOff();

	SMS_setSpriteMode( SPRITEMODE_NORMAL );
	SMS_useFirstHalfTilesforSprites( true );
	SMS_VDPturnOnFeature( VDPFEATURE_HIDEFIRSTCOL );

	engine_asm_manager_clear_VRAM();
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

	load_room(level0401_txt);

	SMS_displayOn();
	for (;;)
	{
		SMS_waitForVBlank();
	}
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!");
#endif
