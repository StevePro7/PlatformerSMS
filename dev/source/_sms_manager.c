#include "_sms_manager.h"
#include "game_manager.h"
#include <stdbool.h>

#ifdef _CONSOLE
#include "..\..\tmp\SMSlib.h"
#else
#include "..\..\lib\SMSlib.h"
#endif

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
void devkit_SMS_mapROMBank( unsigned char n )
{
	SMS_mapROMBank( n );
}

void devkit_SMS_setSpriteMode( unsigned char mode )
{
	SMS_setSpriteMode( mode );
}
void devkit_SMS_useFirstHalfTilesforSprites_False()
{
	SMS_useFirstHalfTilesforSprites( false );
}
void devkit_SMS_useFirstHalfTilesforSprites_True()
{
	SMS_useFirstHalfTilesforSprites( true );
}
void devkit_SMS_VDPturnOnFeature( unsigned int feature )
{
	SMS_VDPturnOnFeature( feature );
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

void devkit_SMS_setNextTileatXY( unsigned char x, unsigned char y )
{
	SMS_setNextTileatXY( x, y );
}
void devkit_SMS_setTile( const unsigned char tile )
{
	SMS_setTile( tile );
}

void devkit_SMS_addSprite( unsigned char x, unsigned char y, unsigned char tile )
{
	SMS_addSprite( x, y, tile );
}
void devkit_SMS_initSprites()
{
	SMS_initSprites();
}
void devkit_SMS_finalizeSprites()
{
	SMS_finalizeSprites();
}
void devkit_SMS_waitForVBlank()
{
	SMS_waitForVBlank();
}
void devkit_SMS_copySpritestoSAT()
{
	SMS_copySpritestoSAT();
}

unsigned int devkit_SMS_getKeysStatus()
{
	return SMS_getKeysStatus();
}

// #defines
unsigned char devkit_SPRITEMODE_NORMAL()
{
	return SPRITEMODE_NORMAL;
}
unsigned int devkit_VDPFEATURE_HIDEFIRSTCOL()
{
	return VDPFEATURE_HIDEFIRSTCOL;
}

unsigned int devkit_PORT_A_KEY_UP()
{
	return PORT_A_KEY_UP;
}
unsigned int devkit_PORT_A_KEY_DOWN()
{
	return PORT_A_KEY_DOWN;
}
unsigned int devkit_PORT_A_KEY_LEFT()
{
	return PORT_A_KEY_LEFT;
}
unsigned int devkit_PORT_A_KEY_RIGHT()
{
	return PORT_A_KEY_RIGHT;
}
unsigned int devkit_PORT_A_KEY_1()
{
	return PORT_A_KEY_1;
}
unsigned int devkit_PORT_A_KEY_2()
{
	return PORT_A_KEY_2;
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER( productCode, revision );
	SMS_EMBED_SDSC_HEADER( verMaj, verMin, dateYear, dateMonth, dateDay, author, name, descr );
#endif