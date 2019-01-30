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

void devkit_SMS_init()
{
	SMS_init();
}
void devkit_SMS_displayOn()
{
	SMS_displayOn();
}
void devkit_SMS_displayOff()
{
	SMS_displayOff();
}

void devkit_SMS_loadPSGaidencompressedTiles( void *src, unsigned int tilefrom )
{
	SMS_loadPSGaidencompressedTiles( src, tilefrom );
}
void devkit_SMS_loadBGPalette( void *palette )
{
	SMS_loadBGPalette( palette );
}
void devkit_SMS_loadSpritePalette( void *palette )
{
	SMS_loadSpritePalette( palette );
}
void devkit_SMS_setSpritePaletteColor( const unsigned char entry, const unsigned char r, const unsigned char g, const unsigned char b )
{
	const unsigned char color = RGB( r, g, b );
	SMS_setSpritePaletteColor( entry, color );
}




#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER( productCode, revision );
	SMS_EMBED_SDSC_HEADER( verMaj, verMin, dateYear, dateMonth, dateDay, author, name, descr );
#endif