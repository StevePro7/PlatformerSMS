#include "main.h"

// Global variables.
bool global_pause;
unsigned char curr_screen_type, next_screen_type;

void( *load_method[ MAX_SCREEENS ] )( );
void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );
void custom_initialize();

void draw_grid();
void draw_floor();
void print( int  px, int  vx, int  dx, unsigned char yy );

void main(void)
{
	//bool test;// = false;
	unsigned char test;
	int i = 0;
	int yy = 0;
	static int px, py;
	static int vx, vy;
	static int dx, dy;
	//int ppx = 0, ppy = 0;
	//int vx = 0, vy = 0;
	//int dx = 0, dy = 0;
	unsigned char bx = 0;

//	int elapsed = 0.02;
	int movement = 0;

	//test = true;
	test = 0;
	px = 96; py = 128;
	vx = 0; vy = 0;
	dx = 0; dy = 0;

	engine_asm_manager_clear_VRAM();
	devkit_SMS_init();
	devkit_SMS_displayOff();

	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_useFirstHalfTilesforSprites_True();						// true changes tile color in Tile Viewer
	//devkit_SMS_VDPturnOnFeature( devkit_VDPFEATURE_HIDEFIRSTCOL() );	// TODO remember to uncomment this...!

	engine_hack_manager_init();


	engine_content_manager_load_sprites();
	engine_content_manager_load_back_tiles();

	//draw_grid();
	draw_floor();
	
	custom_initialize();
	curr_screen_type = screen_type_none;
	//next_screen_type = screen_type_load;
	next_screen_type = screen_type_test;

	//print( px, vx, dx, 0 );
	//engine_input_manager_update();
	
//	print( px, vx, dx, 0 );
	devkit_SMS_displayOn();
	for (;;)
	{
		if( curr_screen_type != next_screen_type )
		{
			curr_screen_type = next_screen_type;
			load_method[ curr_screen_type ]();
		}
		devkit_SMS_initSprites();
		engine_input_manager_update();

		test = engine_input_manager_move_left();
		//engine_font_manager_draw_data( test, 10, 10);
		if( test )
		{
			movement = -1;
			px -= 1;
			//print( px, vx, dx, 1 );
		}
		//else
		//{
			test = engine_input_manager_move_right();
			//engine_font_manager_draw_data( test, 10, 11 );
			if( test )
			{
				movement = 1;
				px += 1;
				//print( px, vx, dx, 2 );
			}
		//}

		//print( px, vx, dx, 1 );
		//engine_sprite_manager_draw_player( px, py );
		engine_sprite_manager_draw_player( px, py );
		//update_method[ curr_screen_type ]( &next_screen_type );

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();
		devkit_SMS_copySpritestoSAT();
	}
}
void print( int  px, int  vx, int  dx, unsigned char yy )
{
	engine_font_manager_draw_data( px, 10, yy );
	engine_font_manager_draw_data( vx, 20, yy );
	engine_font_manager_draw_data( dx, 30, yy );
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
void draw_floor()
{
	unsigned char x;
	enum_tile_type tile_type;
	for( x = 0; x < 32; x += 2 )
	{
		tile_type = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile_type, x, 20 );
		tile_type = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile_type, x, 22 );
	}
}


void custom_initialize()
{
	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	/*
	load_method[ screen_type_init ] = screen_init_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	*/

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	/*
	update_method[ screen_type_init ] = screen_init_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	*/

	// Initialize hack manager.
	engine_hack_manager_init();
	engine_hack_manager_invert();
}


//#ifdef _CONSOLE
//#else
//	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
//	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!");
//#endif
