#include "main.h"

// Global functions.
void custom_initialize();

void main(void)
{
	// Global variables.
	static bool global_pause;
	unsigned char open_screen_type;

	engine_asm_manager_clear_VRAM();
	devkit_SMS_init();
	devkit_SMS_displayOff();

	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_useFirstHalfTilesforSprites_False();						// true changes tile color in Tile Viewer
	devkit_SMS_VDPturnOnFeature( devkit_VDPFEATURE_HIDEFIRSTCOL() );

	engine_content_manager_load_back_tiles();
	engine_content_manager_load_sprites();

	custom_initialize();
	//open_screen_type = screen_type_load;
	//open_screen_type = screen_type_init;
	//open_screen_type = screen_type_test;
	//open_screen_type = screen_type_func;
	//open_screen_type = screen_type_over;
	//open_screen_type = screen_type_title;
	//open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_play;
	//open_screen_type = screen_type_load;
	//open_screen_type = screen_type_cont;
	open_screen_type = screen_type_diff;

	engine_screen_manager_init( open_screen_type );
	devkit_SMS_displayOn();
	for (;;)
	{
		devkit_SMS_initSprites();
		engine_input_manager_update();

		engine_screen_manager_update();

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();
		devkit_SMS_copySpritestoSAT();

		devkit_PSGFrame();
		devkit_PSGSFXFrame();
	}
}

void custom_initialize()
{
	// Initialize hack manager.
	engine_hack_manager_init();
	engine_hack_manager_invert();
}

