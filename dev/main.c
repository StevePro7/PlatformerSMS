#include "main.h"

// Global variables.
bool global_pause;
unsigned char curr_screen_type, next_screen_type;

void( *load_method[ MAX_SCREEENS ] )( );
void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );
void custom_initialize();

void draw_grid();
//void draw_floor();
void print( int  px, int  vx, int  dx, unsigned char yy );

#define COUNT 17
#define MAX_X 5

void main(void)
{
	static bool isJ = false;
	static bool was = false;
	//bool test;// = false;
	static unsigned char test, test1, test2;
	static enum_move_type player_move_type;

	unsigned char sgbX, quoX, remX;
	int i = 0;
	int yy = 0;
	static int px, py;
	static int vx, vy;
	static int dx, dy;
	static signed char jumpIdx;

	//int ppx = 0, ppy = 0;
	//int vx = 0, vy = 0;
	//int dx = 0, dy = 0;
	unsigned char bx = 0;
	//static signed char velY[ COUNT ] = { 11, 9, 7, 6, 6, 5, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	static signed char velY[ COUNT ] = { -11, -9, -7, -6, -6, -5, -4, -4, -3, -3, -2, -2, -2, -1, -1, -1, -1 };
	static signed char grav[ COUNT ] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };	// TODO change last value to 5!

	//static signed char velX[ MAX_X ] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
	static unsigned char velX[ MAX_X ] = { 1, 2, 2, 2, 2 };

	static unsigned char idx = 0;
	static unsigned char player_idxX = 0;
//	int elapsed = 0.02;
	int movement = 1;

	unsigned char force = 2;
	player_move_type = move_type_idle;
	jumpIdx = -1;
	//player_move_type = move_type_left;
	//player_move_type = move_type_rght;

	sgbX = 60;
	//quoX = 3;
	//remX = 2;
	quoX = sgbX / 32;
	remX = sgbX % 32;

	//test = true;
	isJ = false;
	was = false;
	test = 0;  test1 = 0; test2 = 0;
	px = 16; py = 128;
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
	//next_screen_type = screen_type_func;

//	print( sgbX, quoX, remX, 0 );
	//engine_input_manager_update();
	
	//print( px, py, dx, 0 );

	//engine_font_manager_draw_data( px, 10, yy );

	devkit_SMS_displayOn();
	for (;;)
	{
		isJ = false;
		if( curr_screen_type != next_screen_type )
		{
			curr_screen_type = next_screen_type;
			load_method[ curr_screen_type ]();
		}
		devkit_SMS_initSprites();
		engine_input_manager_update();

		//test = engine_input_manager_hold_left();
		dx = 0;
		test1 = engine_input_manager_move_left();
		if( test1 )
		{
			if( move_type_left != player_move_type )
			{
				player_idxX = 0;
				dx = velX[ player_idxX ];
				player_move_type = move_type_left;
				print( player_idxX, dx, player_move_type, 5 );
			}
			else if( move_type_left == player_move_type )
			{
				player_idxX++;
				if( player_idxX > MAX_X - 1 )
				{
					player_idxX = MAX_X - 1;
				}
				dx = velX[ player_idxX ];
				//player_move_type = move_type_left;
				print( player_idxX, dx, player_move_type, 7 );
			}

			//px += dx * ( player_move_type - 1 );
			//print( px, dx, player_move_type, 0 );
		}

		//test = engine_input_manager_hold_right();
		test2 = engine_input_manager_move_right();
		if( test2 )
		{
			if( move_type_rght != player_move_type )
			{
				player_idxX = 0;
				dx = velX[ player_idxX ];
				player_move_type = move_type_rght;
				print( player_idxX, dx, player_move_type, 1 );
			}
			else if( move_type_rght == player_move_type )
			{
				player_idxX++;
				if( player_idxX > MAX_X - 1 )
				{
					player_idxX = MAX_X - 1;
				}
				dx = velX[ player_idxX ];
				//player_move_type = move_type_rght;
				print( player_idxX, dx, player_move_type, 2 );
			}

			//px += dx * player_move_type;
			//print( px, dx, player_move_type, 0 );
		}

		if( !test1 && !test2 )
		{
			player_move_type = move_type_idle;
		}
		if( move_type_idle != player_move_type )
		{
			px += dx * ( player_move_type - 1 );
			print( px, dx, player_move_type, 0 );
		}
		engine_font_manager_draw_data( player_move_type, 20, 10 );

		//test = engine_input_manager_hold_fire1();
		test = engine_input_manager_move_fire1();
		isJ = test;
		if( isJ )
		{
			idx = 0;
			if( !was || jumpIdx >= 0 )
			{
				jumpIdx++;
				//print( isJ, was, jumpIdx, 10 );
			}

			if( 0 <= jumpIdx && jumpIdx < COUNT )
			{
				dy = velY[ jumpIdx ];
				py = py + dy;
				//print( jumpIdx, dy, py, 0 + jumpIdx );
			}
		}
		else
		{
			jumpIdx = -1;
		}
		was = isJ;

		

		/*if( !isJ  && idx  )
		{
			test = engine_input_manager_hold_fire1();
			if( test )
			{
				isJ = true;
				print( 1, 1, 1, 5 );
			}
		}*/

		//if( was )
		//{
			test = engine_input_manager_move_fire2();
			//test = 1;
			if( test )
			{
				dy = grav[ idx ];
				py = py + dy;
				if( py > 128 )
				{
					py = 128;
				}
				
				idx++;
				print( idx, 0, dy, 0 + idx );
				if( idx >= COUNT )
				{
					idx = 0;
					//was = false;
				}

				print( idx, 0, dy, 0 + idx );
			}
		//}

		//if( isJ )
		//{
		//	//test = engine_input_manager_hold_up();
		//	//test = 1;
		//	//if( test )
		//	{
		//		dy = velY[ idx ];
		//		py = py + dy;
		//		print( idx, dy, py, 0 + idx );
		//		idx++;
		//		if( idx >= COUNT )
		//		{
		//			idx = 0;
		//			isJ = false;
		//			was = true;
		//			print( 9, 9, 9, 19 );
		//		}
		//	}
		//}

		

		//print( px, py, dx, 1 );
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
	int b = px;		int c = py;	int d = dx;	int y = yy;

	engine_font_manager_draw_data( px, 10, yy );
	engine_font_manager_draw_data( py, 20, yy );
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
//void draw_floor()
//{
//	unsigned char x;
//	enum_tile_type tile_type;
//	for( x = 0; x < 32; x += 2 )
//	{
//		tile_type = rand() % MAX_BLOCK_TILES + 1;
//		engine_tile_manager_draw_tile( tile_type, x, 20 );
//		tile_type = rand() % MAX_BLOCK_TILES + 1;
//		engine_tile_manager_draw_tile( tile_type, x, 22 );
//	}
//
//	tile_type = rand() % MAX_BLOCK_TILES + 1;
//	engine_tile_manager_draw_tile( tile_type, 14, 12 );	engine_tile_manager_draw_tile( tile_type, 14, 14 );
//	tile_type = rand() % MAX_BLOCK_TILES + 1;
//	engine_tile_manager_draw_tile( tile_type, 14, 18 );	engine_tile_manager_draw_tile( tile_type, 14, 16 );
//
//	//tile_type = rand() % MAX_BLOCK_TILES + 1;
//	//engine_tile_manager_draw_tile( tile_type, 12, 14 );
//}


void custom_initialize()
{
	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;
	/*
	load_method[ screen_type_init ] = screen_init_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	*/

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;
	/*
	update_method[ screen_type_init ] = screen_init_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	*/

	// Initialize hack manager.
	engine_hack_manager_init();
	engine_hack_manager_invert();
}
