#include "player_manager.h"
#include "global_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "input_manager.h"

// Global variable.
struct_player_object global_player_object;

#define MAX_VELOCITY_X	10
#define MAX_VELOCITY_Y	17
#define TILE_COLLISION	16
#define DRAW_OFFSET_X	-4

static unsigned char velocityXgnd[ MAX_VELOCITY_X ] = { 1, 2, 2, 2, 2, 2, 2, 2, 3, 3 };
static unsigned char velocityXair[ MAX_VELOCITY_X ] = { 1, 2, 3, 3, 3, 3, 3, 3, 3, 3 };

static signed char velocityY[ MAX_VELOCITY_Y ] = { -11, -9, -7, -6, -6, -5, -4, -4, -3, -3, -2, -2, -2, -1, -1, -1, -1 };
static signed char gravityZ[ MAX_VELOCITY_Y ] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

static unsigned char leftTileArray[ TILE_COLLISION ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
static unsigned char rghtTileArray[ TILE_COLLISION ] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
static unsigned char topXTileArray[ TILE_COLLISION ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };
static unsigned char botXTileArray[ TILE_COLLISION ] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

// Private helper methods.
static void get_coll_position();
static void get_draw_position();
static void get_common_position( int posX, int posY, signed char offsetX );

void engine_player_manager_load()
{
	struct_player_object *po = &global_player_object;
	po->posnX = 24;	po->posnY = 160;
	po->drawX = 0;	po->drawY = 0;
	po->velX = 0;	po->velY = 0;
	po->player_idxX = 0;
	po->player_move_type = move_type_idle;
	po->isOnGround = true;
}

void engine_player_manager_update()
{
	unsigned char test1, test2;
	struct_player_object *po = &global_player_object;

	test1 = engine_input_manager_move_left();
	if( test1 )
	{
		if( move_type_left != po->player_move_type )
		{
			po->player_move_type = move_type_left;
			po->player_idxX = INVALID_INDEX;
		}
	}

	test2 = engine_input_manager_move_right();
	if( test2 )
	{
		if( move_type_rght != po->player_move_type )
		{
			po->player_move_type = move_type_rght;
			po->player_idxX = INVALID_INDEX;
		}
	}

	if( test1 || test2 )
	{
		//TODO delete debug info
		//engine_font_manager_draw_data( po->player_idxX, 15, 9 );

		po->player_idxX++;
		if( po->player_idxX > MAX_VELOCITY_X - 1 )
		{
			po->player_idxX = MAX_VELOCITY_X - 1;
		}

		po->deltaX = po->isOnGround ? velocityXgnd[ po->player_idxX ] : velocityXair[ po->player_idxX ];
		po->velX = ( po->player_move_type - 1 ) * po->deltaX;
		po->posnX += po->velX;

		//TODO delete debug info
		//engine_font_manager_draw_data( po->player_idxX, 15, 10 );
		//engine_font_manager_draw_data( po->deltaX, 15, 11 );
		//engine_font_manager_draw_data( po->velX, 15, 12 );
		//engine_font_manager_draw_data( po->posX, 15, 13 );
	}
	else
	{
		po->player_move_type = move_type_idle;
	}
}

void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;
	get_draw_position();
	engine_sprite_manager_draw_player( po->drawX, po->drawY );
}

static void get_coll_position()
{
	struct_player_object *po = &global_player_object;
	get_common_position( po->posnX, po->posnY, 0 );
	po->collX = po->commX;
	po->collY = po->commY;
}
static void get_draw_position()
{
	struct_player_object *po = &global_player_object;
	//engine_font_manager_draw_data( po->posnX, 15, 10 );
	//engine_font_manager_draw_data( po->posnY, 15, 11 );
	get_common_position( po->posnX, po->posnY, DRAW_OFFSET_X );
	po->drawX = po->commX;
	po->drawY = po->commY;
	//engine_font_manager_draw_data( po->drawX, 15, 12 );
	//engine_font_manager_draw_data( po->drawY, 15, 13 );
}
static void get_common_position( int posX, int posY, signed char offsetX )
{
	struct_player_object *po = &global_player_object;

	int halfTileSizeX = TILE_WIDE / 2;
	int twiceTileSizeY = 2 * TILE_HIGH;

	po->commX = posX - halfTileSizeX + offsetX;
	po->commY = posY - twiceTileSizeY;

	//engine_font_manager_draw_data( posX, 15, 10 );
	//engine_font_manager_draw_data( halfTileSizeX, 15, 11 );
	//engine_font_manager_draw_data( twiceTileSizeY, 15, 12 );
	//engine_font_manager_draw_data( offsetX, 15, 13 );
	//engine_font_manager_draw_data( po->commX, 15, 14 );
	//engine_font_manager_draw_data( po->commY, 15, 15 );
}