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
	ho->hack_debug = 0;
	ho->hack_invincible = 0;
	ho->hack_difficulty = 0;
	ho->hack_world = 0;
	ho->hack_round = 0;

	// TODO add invincibility AND unlimited lives i.e. can die but play forever
	//ho->hacker_enemy = PEEK( HACKER_START + 0 );	// 0x0050		//

#ifndef _CONSOLE

	ho->hack_debug = PEEK( HACKER_START - 1 );			// 0x004F		// 0=debug on otherwise off.
	ho->hack_invincible = PEEK( HACKER_START + 0 );		// 0x0050		//
	ho->hack_difficulty = PEEK( HACKER_START + 1 );		// 0x0050		//
	ho->hack_world = PEEK( HACKER_START + 2 );			// 0x0051		//
	ho->hack_round = PEEK( HACKER_START + 3 );			// 0x0052		//

#endif

}

void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;

	// Difficulty.
	if( ho->hack_difficulty > diff_type_hard )
	{
		ho->hack_difficulty = diff_type_easy;
	}

	// World.
	if( 0 != ho->hack_world )
	{
		if( ho->hack_world > MAX_WORLDS )
		{
			ho->hack_world = MAX_WORLDS;
		}

		// Zero-based index.
		ho->hack_world -= 1;
	}

	// Round.
	if( 0 != ho->hack_round )
	{
		if( ho->hack_round > MAX_ROUNDS )
		{
			ho->hack_round = MAX_ROUNDS;
		}

		// Zero-based index.
		ho->hack_round -= 1;
	}

	// TODO - IMPORTANT - remove all code here used during testing!!
	ho->hack_invincible = 1;
	//ho->hack_difficulty = diff_type_hard;
	//ho->hack_round = 6;
}