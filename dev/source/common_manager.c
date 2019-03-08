#include "common_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "none_screen.h"
#include "test_screen.h"
#include "init_screen.h"
#include "load_screen.h"
#include "play_screen.h"
#include "func_screen.h"

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init()
{
	curr_screen_type = screen_type_none;
	next_screen_type = screen_type_func;

	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_init ] = screen_init_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;
	/*
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	*/

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_init ] = screen_init_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;
	/*
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	*/
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		load_method[ curr_screen_type ]();
	}

	update_method[ curr_screen_type ]( &next_screen_type );
}