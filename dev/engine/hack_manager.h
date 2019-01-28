#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

extern unsigned char hacker_debug;
extern unsigned char hacker_level;

#define HACKER_START		0x0050

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

#endif//_HACK_MANAGER_H_