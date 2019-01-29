#include "_sms_manager.h"
//#include "..\gfx.h"
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

// TEST_MANAGER
void engine_game_manager_common()
{
	SMS_displayOn();
}
void engine_game_manager_render()
{
	SMS_setSpritePaletteColor( 0, RGB( 1, 3, 1 ) );
}


#ifdef _CONSOLE
#else
SMS_EMBED_SEGA_ROM_HEADER( 9999, 0 );
SMS_EMBED_SDSC_HEADER( 1, 0, 2019, 3, 27, "StevePro Studios", "Platformer", "This is a generic platformer game!" );
#endif