#include "hack_manager.h"

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

// Global variable.
struct_hack_object global_hack_object;

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	ho->hacker_debug = 0;
	ho->hacker_level = 0;

#ifndef _CONSOLE

	ho->hacker_debug = PEEK( HACKER_START - 1 );	// 0x004F		// 0=debug on otherwise off.
	ho->hacker_level = PEEK( HACKER_START + 0 );	// 0x0050		//

#endif

}

void engine_hack_manager_invert()
{
}