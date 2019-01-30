#ifndef _SMS_MANAGER_H_
#define _SMS_MANAGER_H_

void devkit_SMS_init();
void devkit_SMS_displayOn();
void devkit_SMS_displayOff();

void devkit_SMS_setSpriteMode_Normal();
void devkit_SMS_useFirstHalfTilesforSprites_True();
void devkit_SMS_VDPturnOnFeature_HideFirstCol();

void devkit_SMS_loadPSGaidencompressedTiles( const void *src, unsigned int tilefrom );
void devkit_SMS_loadBGPalette( void *palette );
void devkit_SMS_loadSpritePalette( void *palette );
void devkit_SMS_setSpritePaletteColor( const unsigned char entry, const unsigned char r, const unsigned char g, const unsigned char b );

void devkit_SMS_setNextTileatXY( unsigned char x, unsigned char y );
void devkit_SMS_setTile( const unsigned char tile );

void devkit_SMS_addSprite( unsigned char x, unsigned char y, unsigned char tile );

void devkit_SMS_initSprites();
void devkit_SMS_finalizeSprites();
void devkit_SMS_waitForVBlank();
void devkit_SMS_copySpritestoSAT();

#endif//_SMS_MANAGER_H_