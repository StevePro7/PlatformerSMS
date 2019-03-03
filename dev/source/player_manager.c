#include "player_manager.h"
#include "global_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "level_manager.h"
#include "input_manager.h"
//#include <math.h>

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
	//#pragma disable_warning 110
#endif

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
static int do_jump( int inpVelocityY );
static void get_coll_position();
static void get_draw_position();
static void get_common_position( int posX, int posY, signed char offsetX );
static void process_collision( int rectALeft, int rectATop, int rectBLeft, int rectBTop );

void engine_player_manager_load()
{
	struct_player_object *po = &global_player_object;

	// Calculate player starting spot based on level.
	int rectX, rectB;
	po->posnX = 0;	po->posnY = 0;
	rectX = po->spotX * TILE_WIDE;
	rectB = po->spotY * TILE_HIGH + TILE_HIGH;
	po->posnX = rectX + TILE_WIDE / 2;
	po->posnY = rectB;

	//po->posnX = 8*16+24;	po->posnY = 32;		// TODO on the base stevepro
	po->player_move_type = move_type_idle;
	//po->posnX = 24 + 4* 16;	po->posnY = 160;
	//po->posnX = 24 + 4 * 16;	po->posnY = 32;
	po->drawX = 0;	po->drawY = 0;
	po->collX = 0;	po->collX = 0;
	po->prevX = 0;	po->prevX = 0;
	po->commX = 0;	po->commY = 0;
	po->velX = 0;	po->velY = 0;
	po->deltaX = 0;	po->deltaY = 0;
	po->player_idxX = 0;	po->player_idxY = 0;	po->player_grav = 0;
	po->depthX = 0;	po->depthY = 0;
	po->isOnGround = true;
	po->isJumping = false;
	po->wasJumping = false;
	po->jumpFrame = 0;
	po->coll_horz = 0;	po->coll_vert = 0;
	po->previousBottom = 0;
}

void engine_player_manager_update()
{
	struct_player_object *po = &global_player_object;
	po->player_move_type = move_type_idle;
	po->velX = 0;

	engine_player_manager_get_input();
}

void engine_player_manager_get_input()
{
	struct_player_object *po = &global_player_object;
	unsigned char test1, test2;

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

	po->isJumping = engine_input_manager_move_fire1();

	if( test1 || test2 )
	{
		po->player_idxX++;
		if( po->player_idxX > MAX_VELOCITY_X - 1 )
		{
			po->player_idxX = MAX_VELOCITY_X - 1;
		}

		po->deltaX = po->isOnGround ? velocityXgnd[ po->player_idxX ] : velocityXair[ po->player_idxX ];
		po->velX = ( po->player_move_type - 1 ) * po->deltaX;
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

	/*if( move_type_idle != po->player_move_type )
	{
		po->player_idxX++;
		if( po->player_idxX > MAX_VELOCITY_X - 1 )
		{
			po->player_idxX = MAX_VELOCITY_X - 1;
		}

		po->deltaX = po->isOnGround ? velocityXgnd[ po->player_idxX ] : velocityXair[ po->player_idxX ];
		po->velX = ( po->player_move_type - 1 ) * po->deltaX;
	}*/

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

	po->velY = do_jump( po->velY );

	po->posnX += po->velX;
	// TODO update this code
	if( po->posnX <= 12 )
	{
		po->posnX = 12;
	}
	if( po->posnX >= 232 )
	{
		po->posnX = 232;
	}

	po->posnY += po->velY;
	if( po->posnY >= 192 )
	{
		engine_font_manager_draw_text( "DEAD", 20, 20 );
	}
}

void engine_player_manager_handle_collisions()
{
	struct_player_object *po = &global_player_object;

	unsigned char int_coll_type;
	enum_coll_type coll_type;
	int boundsLeft, boundsTopX, boundsBotX;
	int tileBoundsLeft, tileBoundsTopX;

	unsigned char leftTile, rghtTile, topXTile, botXTile;
	unsigned char idxLeftTile, idxRghtTile, idxTopXTile, idxBotXTile;
	unsigned char x, y;

	int idxX, idxY;	//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
	//unsigned char idxX, idxY;		// TODO ensure that will NOT overflow i.e. >= 256 if btwn 8 and 15*16+8 then should be OK
	signed char quoX, remX;
	signed char quoY, remY;

	//float absDepthX, absDepthY;
	int absDepthX, absDepthY;
	boundsLeft = po->posnX - halfBoundsWidth;
	boundsTopX = po->posnY - localBoundsHeight;

	// Pg.97 Teach Yourself C in 24hrs
	leftTile = rghtTile = topXTile = botXTile = 0;
	idxX = idxY = 0;
	quoX = quoY = remX = remY = 0;

	get_coll_position();

	// Determine left + rght tile lookups.
	idxX = po->collX;
	quoX = idxX / TILE_WIDE;
	remX = idxX % TILE_WIDE;

	idxLeftTile = leftTileArray[ remX ];
	idxRghtTile = rghtTileArray[ remX ];
	leftTile = idxLeftTile + quoX;
	rghtTile = idxRghtTile + quoX;

	// Determine topX + botX tile lookups.
	topXTile = 0;
	botXTile = 1;
	if( po->collY >= 0 )
	{
		idxY = po->collY;
		quoY = idxY / TILE_HIGH;
		remY = idxY % TILE_HIGH;

		idxTopXTile = topXTileArray[ remY ];
		idxBotXTile = botXTileArray[ remY ];
		topXTile = idxTopXTile + quoY;
		botXTile = idxBotXTile + quoY;
	}

	idxTopXTile = topXTileArray[ remY ];
	idxBotXTile = botXTileArray[ remY ];
	topXTile = idxTopXTile + quoY;
	botXTile = idxBotXTile + quoY;

	// Reset flag to search for ground collision.
	po->isOnGround = false;

	// if player in between tiles then don't check for collisions with gems or exit.
	po->coll_horz = INVALID_INDEX;
	po->coll_vert = INVALID_INDEX;
	if( leftTile == rghtTile )
	{
		po->coll_horz = leftTile;
		po->coll_vert = topXTile;
	}

	// For each potentially colliding tile,
	for( y = topXTile; y <= botXTile; ++y )
	{
		for( x = leftTile; x <= rghtTile; ++x )
		{
			// If this tile is collidable,
			engine_level_manager_get_collision( &int_coll_type, x, y );
			coll_type = ( enum_coll_type ) int_coll_type;

			if( coll_type_passable != coll_type )
			{
				// Determine collision depth (with direction) and magnitude.
				tileBoundsLeft = x * TILE_WIDE;
				tileBoundsTopX = y * TILE_HIGH;

				process_collision( boundsLeft, boundsTopX, tileBoundsLeft, tileBoundsTopX );
				if( 0 != po->depthX || 0 != po->depthY )
				{
					//absDepthX = fabsf( ( float ) po->depthX );
					//absDepthY = fabsf( ( float ) po->depthY );
					absDepthX = myabs( po->depthX );
					absDepthY = myabs( po->depthY );


					// Resolve the collision along the shallow axis.
					if( absDepthY < absDepthX || coll_type_platform == coll_type )
					{
						// If we crossed the top of a tile, we are on the ground.
						if( po->previousBottom <= tileBoundsTopX )
						{
							po->isOnGround = true;
						}

						// Ignore platforms, unless we are on the ground.
						if( coll_type_impassable == coll_type || po->isOnGround )
						{
							// Resolve the collision along the Y axis.
							po->posnY = po->posnY + po->depthY;

							// Perform further collisions with the new bounds.
							boundsLeft = po->posnX - halfBoundsWidth;
							boundsTopX = po->posnY - localBoundsHeight;
						}
					}
					else if( coll_type_impassable == coll_type ) // Ignore platforms.
					{
						// Resolve the collision along the X axis.
						po->posnX = po->posnX + po->depthX;

						// Perform further collisions with the new bounds.
						boundsLeft = po->posnX - halfBoundsWidth;
						boundsTopX = po->posnY - localBoundsHeight;
					}
				}
			}
		}
	}

	// Save the new bounds bottom.
	boundsLeft = po->posnX - halfBoundsWidth;
	boundsTopX = po->posnY - localBoundsHeight;
	boundsBotX = boundsTopX + localBoundsHeight;
	po->previousBottom = boundsBotX;
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
		po->velY = 0;
		po->player_grav = 0;
		po->jumpFrame = 0;
	}
}

void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;
	if( po->posnY >= 0 )
	{
		get_draw_position();
		engine_sprite_manager_draw_player( po->drawX, po->drawY );
	}
}

static int do_jump( int inpVelocityY )
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
	return inpVelocityY;
	//po->velY = inpVelocityY;
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
	get_common_position( po->posnX, po->posnY, DRAW_OFFSET_X );
	po->drawX = po->commX;
	po->drawY = po->commY;
}
static void get_common_position( int posX, int posY, signed char offsetX )
{
	struct_player_object *po = &global_player_object;

	int halfTileSizeX = TILE_WIDE / 2;
	int twiceTileSizeY = 2 * TILE_HIGH;

	po->commX = posX - halfTileSizeX + offsetX;
	po->commY = posY - twiceTileSizeY;
}
static void process_collision( int rectALeft, int rectATop, int rectBLeft, int rectBTop )
{
	struct_player_object *po = &global_player_object;

	int centerAX, centerAY;
	int centerBX, centerBY;
	int distanceX, distanceY;
	int minDistanceX, minDistanceY;
	//float fDistanceX, fDistanceY;
	int fDistanceX, fDistanceY;

	// Calculate half sizes.	DONE

	// Calculate centers.
	centerAX = rectALeft + halfWidthA;
	centerAY = rectATop + halfHeightA;
	centerBX = rectBLeft + halfWidthB;
	centerBY = rectBTop + halfHeightB;

	// Calculate current and minimum-non-intersecting distances between centers.
	distanceX = centerAX - centerBX;
	distanceY = centerAY - centerBY;

	minDistanceX = halfWidthA + halfWidthB;
	minDistanceY = halfHeightA + halfHeightB;

	po->depthX = 0;
	po->depthY = 0;

	// If we are not intersecting at all, return (0, 0).
	//fDistanceX = fabsf( ( float ) distanceX );
	//fDistanceY = fabsf( ( float ) distanceY );

	fDistanceX = myabs( distanceX );
	fDistanceY = myabs( distanceY );

	if( fDistanceX >= minDistanceX || fDistanceY >= minDistanceY )
	{
		return;
	}

	// Calculate and return intersection depths.
	po->depthX = distanceX > 0 ? minDistanceX - distanceX : -minDistanceX - distanceX;
	po->depthY = distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY;
}
