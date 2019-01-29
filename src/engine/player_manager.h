#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

//extern struct_player_object player_object;
//extern struct MyStruct theVar;

void engine_player_manager_load()
{
	//playershoot *ps = &playershoots[ 0 ];
	//playershoot *ps = &playershoot1;
	//ps->playershoottype = 10;

	struct_player_object *po = &player_object;
	po->sx = 128;
	po->sy = 144;
	po->bl = 32;
	po->br = 192;
	po->vx = +1;
	po->vy = 0;
	po->fr = 0;
	po->fm = 5;
	//engine_font_manager_draw_text( "PLAY SCREEN...", 0, 1 );
}

void engine_player_manager_animate( unsigned char index )
{
	const unsigned char *tilemap = ( unsigned char * ) stageinitdata[ index ];
	SMS_loadPSGaidencompressedTiles( tilemap, list_sprite_tile_offset[ sprite_type_player ] );
}

void engine_player_manager_update()
{
	unsigned index;
	struct_player_object *po = &player_object;

	index = po->fr;
	engine_player_manager_animate( index );
	//po->fr++;
	if( po->fr >= po->fm )
	{
		po->fr = 0;
	}

	po->sx += po->vx;
	if( po->sx <= po->bl || po->sx >= po->br )
	{
		po->vx = -po->vx;
		//po->vx = 0;
	}
}

void engine_player_manager_draw()
{
	unsigned char x, y;
	struct_player_object *po = &player_object;

	x = po->sx + GAME_X_OFFSET;
	y = po->sy;
	engine_sprite_manager_draw_player( x, y );
}

#endif//_PLAYER_MANAGER_H_