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

#define COUNT 17

void main(void)
{
	static bool isJ = false;
	static bool was = false;
	//bool test;// = false;
	static unsigned char test;
	int i = 0;
	int yy = 0;
	static int px, py;
	static int vx, vy;
	static int dx, dy;
	//int ppx = 0, ppy = 0;
	//int vx = 0, vy = 0;
	//int dx = 0, dy = 0;
	unsigned char bx = 0;
	static signed char velY[ COUNT ] = { 11, 9, 7, 6, 6, 5, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	static signed char grav[ COUNT ] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6 };	// TODO change last value to 5!
	static unsigned char idx = 0;
//	int elapsed = 0.02;
	int movement = 1;

	//test = true;
	isJ = false;
	was = false;
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
	//draw_floor();
	
	custom_initialize();
	curr_screen_type = screen_type_none;
	//next_screen_type = screen_type_load;
	next_screen_type = screen_type_test;

	//print( px, py, dx, 0 );
	//engine_input_manager_update();
	
//	print( px, py, dx, 0 );
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

		//test = engine_input_manager_hold_left();
		////engine_font_manager_draw_data( test, 10, 10);
		//if( test )
		//{
		//	px -= movement;
		//}
		//test = engine_input_manager_hold_right();
		//if( test )
		//{
		//	px += movement;
		//}
		//test = engine_input_manager_hold_up();
		//if( test )
		//{
		//	py -= movement;
		//}
		//test = engine_input_manager_move_down();
		//if( test )
		//{
		//	if( py >= 128 )
		//	{
		//		py = 128;
		//	}
		//	else
		//	{
		//		py += movement;
		//	}
		//}

		if( !isJ  && !was )
		{
			test = engine_input_manager_hold_fire1();
			if( test )
			{
				isJ = true;
				print( 1, 1, 1, 5 );
			}
			test = engine_input_manager_hold_fire2();
			if( test )
			{
				was = true;
				print( 2, 2, 2, 6 );
			}
		}

		if( isJ )
		{
			//test = engine_input_manager_hold_left();
			//test = 1;
			//if( test )
			{
				dy = velY[ idx ];
				py = py - dy;
				//print( idx, 0, dy, 0 + idx );
				idx++;
				if( idx >= COUNT )
				{
					idx = 0;
					isJ = false;
				}
			}
		}
		if( was )
		{
			//test = engine_input_manager_hold_left();
			//test = 1;
			//if( test )
			{
				dy = grav[ idx ];
				py = py + dy;
				//print( idx, 0, dy, 0 + idx );
				idx++;
				if( idx >= COUNT )
				{
					idx = 0;
					was = false;
				}
			}
		}

		print( px, py, dx, 1 );
		engine_sprite_manager_draw_player( px, py );
		//engine_sprite_manager_draw( px, py, sprite_type_enemyD );
		update_method[ curr_screen_type ]( &next_screen_type );

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();
		devkit_SMS_copySpritestoSAT();
	}
}
void print( int  px, int  py, int  dx, unsigned char yy )
{
	engine_font_manager_draw_data( px, 10, yy );
	engine_font_manager_draw_data( py, 30, yy );
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

	tile_type = rand() % MAX_BLOCK_TILES + 1;
	engine_tile_manager_draw_tile( tile_type, 14, 12 );	engine_tile_manager_draw_tile( tile_type, 14, 14 );
	tile_type = rand() % MAX_BLOCK_TILES + 1;
	engine_tile_manager_draw_tile( tile_type, 14, 18 );	engine_tile_manager_draw_tile( tile_type, 14, 16 );

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 12, 14 );
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
