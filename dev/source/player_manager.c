#include "player_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "input_manager.h"

// Global variable.
struct_player_object global_player_object;

#define MAX_VELOCITY_X	10
#define MAX_VELOCITY_Y	17

static unsigned char velocityXgnd[ MAX_VELOCITY_X ] = { 1, 2, 2, 2, 2, 2, 2, 2, 3, 3 };
static unsigned char velocityXair[ MAX_VELOCITY_X ] = { 1, 2, 3, 3, 3, 3, 3, 3, 3, 3 };

static signed char velocityY[ MAX_VELOCITY_Y ] = { -11, -9, -7, -6, -6, -5, -4, -4, -3, -3, -2, -2, -2, -1, -1, -1, -1 };
static signed char gravityZ[ MAX_VELOCITY_Y ] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

void engine_player_manager_load()
{
	struct_player_object *po = &global_player_object;
	po->posX = 12;	po->posY = 0;
	po->velX = 0;	po->velY = 0;
	po->player_idxX = 0;
	po->player_move_type = move_type_idle;
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
			po->player_idxX = 0;
		}
		else
		{
			po->player_idxX++;
			if( po->player_idxX > MAX_VELOCITY_X - 1 )
			{
				po->player_idxX = MAX_VELOCITY_X - 1;
			}
		}
	}

	test2 = engine_input_manager_move_right();
	if( test2 )
	{
		if( move_type_rght != po->player_move_type )
		{
			po->player_move_type = move_type_rght;
			po->player_idxX = 0;
		}
		else
		{
			po->player_idxX++;
			if( po->player_idxX > MAX_VELOCITY_X - 1 )
			{
				po->player_idxX = MAX_VELOCITY_X - 1;
			}
		}
	}

	if( test1 || test2 )
	{
		po->deltaX = velocityXgnd[ po->player_idxX ];
		po->velX = ( po->player_move_type - 1 ) * po->deltaX;
		po->posX += po->velX;

		/*engine_font_manager_draw_data( po->player_idxX, 15, 10 );
		engine_font_manager_draw_data( po->deltaX, 15, 11 );
		engine_font_manager_draw_data( po->velX, 15, 12 );
		engine_font_manager_draw_data( po->posX, 15, 13 );*/
	}
	else
	{
		po->player_move_type = move_type_idle;
	}
}

void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;
	engine_sprite_manager_draw_player( po->posX, po->posY );
}