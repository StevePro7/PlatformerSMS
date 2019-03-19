#include "enemy_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "sprite_manager.h"

// Global variables.
struct_enemy_master global_enemy_master;
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

#define DRAW_OFFSET_X	-4

static unsigned int enemy_tiles[ MAX_ENEMIES ] =
{
	ENEMYX_SPRITE_TILE + 0 * SPRITE_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 1 * SPRITE_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 2 * SPRITE_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 3 * SPRITE_TILES_NUMBER
};

static void get_enemy_draw_position( unsigned char idx );
static void get_guard_draw_position( unsigned char idx );

void engine_enemyX_manager_init()
{
	struct_enemy_object *eo;
	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->spotX = 0;
		eo->spotY = 0;
	}
}

void engine_enemyX_manager_load()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;

	// Calculate enemys starting spot based on level.
	int rectX, rectB;
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		eo->posnX = 0;	eo->posnY = 0;
		rectX = eo->spotX * TILE_WIDE;
		rectB = eo->spotY * TILE_HIGH + TILE_HIGH;
		eo->posnX = rectX + TILE_WIDE / 2;
		eo->posnY = rectB;

		if( action_type_chase == eo->action_type )
		{
			get_enemy_draw_position( idx );
		}
		else if( action_type_guard == eo->action_type )
		{
			get_guard_draw_position( idx );
		}
	}
}

void engine_enemyX_manager_draw_enemys()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	unsigned int tile;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( action_type_chase != eo->action_type )
		{
			continue;
		}

		get_enemy_draw_position( idx );
		tile = enemy_tiles[ eo->sprite_type ];
		engine_sprite_manager_draw( eo->drawX, eo->drawY, tile );
	}
}

void engine_enemyX_manager_draw_guards()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( action_type_guard != eo->action_type )
		{
			continue;
		}

		engine_tile_manager_draw_guard( eo->drawX, eo->drawY, eo->sprite_type );
	}
}

static void get_enemy_draw_position( unsigned char idx )
{
	struct_enemy_object *eo = &global_enemy_objects[ idx ];

	int halfTileSizeX = TILE_WIDE / 2;
	int twiceTileSizeY = 2 * TILE_HIGH;

	eo->drawX = eo->posnX - halfTileSizeX + DRAW_OFFSET_X;
	eo->drawY = eo->posnY - twiceTileSizeY;
}

static void get_guard_draw_position( unsigned char idx )
{
	struct_enemy_object *eo = &global_enemy_objects[ idx ];

	// Block 16x16 = 2 * 8x8.
	eo->drawX = eo->spotX * 2;
	eo->drawY = ( eo->spotY - 1 ) * 2;
}