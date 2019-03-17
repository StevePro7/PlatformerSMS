#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

// Global variable.
struct_hack_object global_hack_object;

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	ho->hacker_debug = 0;
	ho->hacker_difficulty = 0;
	ho->hacker_world = 0;
	ho->hacker_round = 0;
	//ho->hacker_enemy = 0;

	// TODO add invincibility AND unlimited lives i.e. can die but play forever
	//ho->hacker_enemy = PEEK( HACKER_START + 0 );	// 0x0050		//

#ifndef _CONSOLE

	ho->hacker_debug = PEEK( HACKER_START - 1 );	// 0x004F		// 0=debug on otherwise off.
	ho->hacker_difficulty = PEEK( HACKER_START + 0 );	// 0x0050		//
	ho->hacker_world = PEEK( HACKER_START + 1 );	// 0x0051		//
	ho->hacker_round = PEEK( HACKER_START + 2 );	// 0x0052		//
	//ho->hacker_enemy = PEEK( HACKER_START + 0 );	// 0x0050		//

#endif

}

void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;

	// Difficulty.
	if( ho->hacker_difficulty > diff_type_hard )
	{
		ho->hacker_difficulty = diff_type_easy;
	}

	// World.
	if( 0 != ho->hacker_world )
	{
		if( ho->hacker_world > MAX_WORLDS )
		{
			ho->hacker_world = MAX_WORLDS;
		}

		// Zero-based index.
		ho->hacker_world -= 1;
	}

	// Round.
	if( 0 != ho->hacker_round )
	{
		if( ho->hacker_round > MAX_ROUNDS )
		{
			ho->hacker_round = MAX_ROUNDS;
		}

		// Zero-based index.
		ho->hacker_round -= 1;
	}

	// TODO - IMPORTANT - remove all code here used during testing!!
	//ho->hacker_difficulty = diff_type_hard;
}