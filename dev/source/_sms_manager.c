#include "_sms_manager.h"
#include "game_manager.h"
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
void devkit_SMS_setSpritePaletteColor( const unsigned char entry, const unsigned char r, const unsigned char g, const unsigned char b )
{
	const unsigned char color = RGB( r, g, b );
	//SMS_setSpritePaletteColor( 0, RGB( 1, 3, 1 ) );
	SMS_setSpritePaletteColor( entry, color );
}


#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER( productCode, revision );
	SMS_EMBED_SDSC_HEADER( verMaj, verMin, dateYear, dateMonth, dateDay, author, name, descr );
#endif