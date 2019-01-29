#include "_sms_manager.h"
#include "..\gfx.h"
#include <stdbool.h>

#ifdef _CONSOLE
#include "..\..\tmp\SMSlib.h"
#else
#include "..\..\lib\SMSlib.h"
#endif

// GAME_MANAGER
void engine_game_manager_init()
{
	SMS_init();
	SMS_displayOff();
	SMS_setSpriteMode( SPRITEMODE_NORMAL );
	SMS_useFirstHalfTilesforSprites( true );
	SMS_VDPturnOnFeature( VDPFEATURE_HIDEFIRSTCOL );
}


#ifdef _CONSOLE
#else
//engine_game_manager_head();
SMS_EMBED_SEGA_ROM_HEADER( 9999, 0 );
SMS_EMBED_SDSC_HEADER( 1, 0, 2019, 3, 27, "StevePro Studios", "Platformer", "This is a generic platformer game!" );
#endif