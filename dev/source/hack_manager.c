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
	ho->hacker_world = 0;
	ho->hacker_round = 0;
	ho->hacker_enemy = 0;

	// TODO add invincibility AND unlimited lives i.e. can die but play forever
	//ho->hacker_enemy = PEEK( HACKER_START + 0 );	// 0x0050		//

#ifndef _CONSOLE

	ho->hacker_debug = PEEK( HACKER_START - 1 );	// 0x004F		// 0=debug on otherwise off.
	ho->hacker_level = PEEK( HACKER_START + 0 );	// 0x0050		//
	ho->hacker_world = PEEK( HACKER_START + 1 );	// 0x0051		//
	ho->hacker_round = PEEK( HACKER_START + 2 );	// 0x0052		//
	ho->hacker_enemy = PEEK( HACKER_START + 0 );	// 0x0050		//

#endif

	ho->hacker_enemy = 3;			// TODO delete this

}

void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;
	//ho->hacker_enemy = 4;
}