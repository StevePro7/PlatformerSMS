#include "hack_manager.h"
#include "enum_manager.h"
#include "tile_manager.h"

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

unsigned char hacker_debug;
unsigned char hacker_level;

void engine_hack_manager_init()
{
	hacker_debug = 0;
	hacker_level = 0;

#ifndef _CONSOLE

	hacker_debug = PEEK( HACKER_START - 1 );	// 0x004F		// 0=debug on otherwise off.
	hacker_level = PEEK( HACKER_START + 0 );	// 0x0050		//

#endif
}

void engine_hack_manager_invert()
{
}

void engine_hack_manager_draw_grid()
{
	unsigned char x, y;
	for( y = 0; y < 24; y += 2 )
	{
		for( x = 0; x < 32; x += 2 )
		{
			engine_tile_manager_draw_tile( tile_type_gridline, x, y );
		}
	}
}