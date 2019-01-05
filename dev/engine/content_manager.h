#ifndef _CONTENT_MANAGER_H_
#define _CONTENT_MANAGER_H_

#define BACK_TILES_OFFSET	0

void engine_content_manager_load_back_tiles()
{
	// Back tiles.
	SMS_loadPSGaidencompressedTiles( back_tiles__tiles__psgcompr, BACK_TILES_OFFSET );
	SMS_loadBGPalette( ( void * ) back_tiles__palette__bin );
}

#endif//_CONTENT_MANAGER_H_