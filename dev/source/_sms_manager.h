#ifndef _SMS_MANAGER_H_
#define _SMS_MANAGER_H_

// GAME_MANAGER
void engine_game_manager_init();

void devkit_SMS_init();
void devkit_SMS_displayOn();
void devkit_SMS_displayOff();

void devkit_SMS_loadPSGaidencompressedTiles( const void *src, unsigned int tilefrom );
void devkit_SMS_loadBGPalette( void *palette );
void devkit_SMS_loadSpritePalette( void *palette );
void devkit_SMS_setSpritePaletteColor( const unsigned char entry, const unsigned char r, const unsigned char g, const unsigned char b );


#endif//_SMS_MANAGER_H_