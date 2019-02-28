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
static signed char gravityZZ[ MAX_VELOCITY_Y ] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

static unsigned char leftTileArray[ TILE_COLLISION ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
static unsigned char rghtTileArray[ TILE_COLLISION ] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
static unsigned char topXTileArray[ TILE_COLLISION ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };
static unsigned char botXTileArray[ TILE_COLLISION ] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

#define localBoundsWidth	12
#define localBoundsHeight	26
#define halfBoundsWidth		localBoundsWidth / 2

#define rectAWidth			localBoundsWidth
#define rectAHeight			localBoundsHeight
#define rectBWidth			TILE_WIDE
#define rectBHeight			TILE_HIGH

#define halfWidthA			rectAWidth / 2
#define halfHeightA			rectAHeight / 2
#define halfWidthB			rectBWidth / 2
#define halfHeightB			rectBHeight / 2

// Private helper methods.
static void do_jump( int inpVelocityY );
static void get_coll_position();
static void get_draw_position();
static void get_common_position( int posX, int posY, signed char offsetX );

void engine_player_manager_load()
{
	struct_player_object *po = &global_player_object;
	//po->posnX = 24;	po->posnY = 160;		// TODO on the base stevepro
	po->posnX = 24;	po->posnY = 32;
	po->drawX = 0;	po->drawY = 0;
	po->velX = 0;	po->velY = 0;
	po->player_idxX = 0;
	po->player_move_type = move_type_idle;
	po->isOnGround = true;
	po->isJumping = false;
	po->wasJumping = false;
	po->jumpFrame = 0;

	//engine_font_manager_draw_data( halfWidthA, 15, 10 );
	//engine_font_manager_draw_data( halfHeightA, 15, 11 );
	//engine_font_manager_draw_data( halfWidthB, 15, 12 );
	//engine_font_manager_draw_data( halfHeightB, 15, 13 );
}

void engine_player_manager_get_input()
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

	//po->isJumping = engine_input_manager_move_fire1();

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
		//po->posnX += po->velX;

		//TODO delete debug info
		//engine_font_manager_draw_data( po->player_idxX, 15, 10 );
		//engine_font_manager_draw_data( po->deltaX, 15, 11 );
		//engine_font_manager_draw_data( po->velX, 15, 12 );
		//engine_font_manager_draw_data( po->posX, 15, 13 );
	}
	else
	{
		po->player_move_type = move_type_idle;
		po->velX = 0;
	}
}

// TODO debug this method to ensure all calculations correct!
void engine_player_manager_apply_physics()
{
	struct_player_object *po = &global_player_object;
	po->prevX = po->posnX;
	po->prevY = po->posnY;

	if( !po->isOnGround )
	{
		po->player_grav++;
		if( po->player_grav > MAX_VELOCITY_Y - 1 )
		{
			po->player_grav = MAX_VELOCITY_Y - 1;
		}
	}
	else
	{
		po->player_grav = 0;
	}

	po->deltaY = gravityZZ[ po->player_grav ];
	po->velY = po->deltaY;

	//engine_font_manager_draw_data( po->velY, 15, 10 );		// TODO delete
	//do_jump( po->velY );
	//engine_font_manager_draw_data( po->velY, 15, 11 );		// TODO delete

	po->posnX += po->velX;
	po->posnY += po->velY;									// TODO revert - IMPORTANT
}

void engine_player_manager_handle_collisions()
{
	struct_player_object *po = &global_player_object;
	int boundsLeft;
	int boundsTopX;

	int leftTile, rghtTile, topXTile, botXTile;
	int idxLeftTile, idxRghtTile, idxTopXTile, idxBotXTile;
	//int idxX, idxY;	//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
	unsigned char idxX, idxY;		// TODO ensure that will NOT overflow i.e. >= 256 if btwn 8 and 15*16+8 then should be OK
	unsigned char quoX, remX;
	unsigned char quoY, remY;

	boundsLeft = po->posnX - halfBoundsWidth;
	boundsTopX = po->posnY - localBoundsHeight;

	// Pg.97 Teach Yourself C in 24hrs
	leftTile = rghtTile = topXTile = botXTile = 0;

	get_coll_position();

	// Determine left + rght tile lookups.
	idxX = po->collX;
	idxX = 248;
	quoX = idxX / TILE_WIDE;
	remX = idxX % TILE_WIDE;

	idxLeftTile = leftTileArray[ remX ];
	idxRghtTile = rghtTileArray[ remX ];
	leftTile = idxLeftTile + quoX;
	rghtTile = idxRghtTile + quoX;

	// Determine topX + botX tile lookups.
	idxY = po->collY;
	quoY = idxY / TILE_HIGH;
	remY = idxY % TILE_HIGH;

	idxTopXTile = topXTileArray[ remY ];
	idxBotXTile = botXTileArray[ remY ];
	topXTile = idxTopXTile + quoY;
	botXTile = idxBotXTile + quoY;

	// Reset flag to search for ground collision.
	po->isOnGround = false;

	//engine_font_manager_draw_data( idxTopXTile, 15, 10 );
	//engine_font_manager_draw_data( idxBotXTile, 15, 11 );
	//engine_font_manager_draw_data( topXTile, 15, 12 );
	//engine_font_manager_draw_data( botXTile, 15, 13 );
}

void engine_player_manager_cleanup()
{
	struct_player_object *po = &global_player_object;
	if( po->posnX == po->prevX )
	{
		po->velX = 0;
	}

	if( po->posnY == po->prevY )
	{
		po->velX = 0;
		po->player_grav = 0;
		po->jumpFrame = 0;
	}
}

void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;
	get_draw_position();
	engine_sprite_manager_draw_player( po->drawX, po->drawY );
}

static void do_jump( int inpVelocityY )
{
	struct_player_object *po = &global_player_object;
	if( !po->isJumping && po->jumpFrame > 0 || po->isJumping && po->jumpFrame >= MAX_VELOCITY_Y )
	{
		po->player_grav = 0;
		inpVelocityY = 0;
	}

	// If the player wants to jump
	if( po->isJumping )
	{
		// Begin or continue a jump
		if( ( !po->wasJumping && po->isOnGround ) || po->jumpFrame > 0 )
		{
			po->jumpFrame++;
		}

		// If we are in the ascent of the jump
		if( 0 < po->jumpFrame && po->jumpFrame <= MAX_VELOCITY_Y )
		{
			// Fully override the vertical velocity with a power curve that gives players more control over the top of the jump
			po->deltaY = velocityY[ po->player_idxY ];
			inpVelocityY = po->deltaY;

			po->player_idxY++;
			if( po->player_idxY > MAX_VELOCITY_Y - 1 )
			{
				po->player_idxY = MAX_VELOCITY_Y - 1;
			}
		}
		else
		{
			// Reached the apex of the jump
			po->player_idxY = 0;
			po->jumpFrame = 0;
		}
	}
	else
	{
		// Continues not jumping or cancels a jump in progress
		po->player_idxY = 0;
		po->jumpFrame = 0;
	}

	po->wasJumping = po->isJumping;
	po->velY = inpVelocityY;
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