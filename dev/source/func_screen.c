#include "func_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include <math.h>
#include <stdlib.h>

static int myabs( int v )
{
	return v * ( ( v < 0 ) * ( -1 ) + ( v > 0 ) );
}

static signed char velocityY[ 1 ] = { -11 };


static int do_jump( int inpVelocityY )
{
	//unsigned char deltaY = velocityY[ 0 ];				// Messes things up and creates 245 NOT 65525
	signed char deltaY = velocityY[ 0 ];
	engine_font_manager_draw_data( deltaY, 10, 11 );

	inpVelocityY = deltaY;
	engine_font_manager_draw_data( inpVelocityY, 10, 12 );

	return inpVelocityY;
}

void screen_func_screen_load()
{
	//float data = -5;
	//float test = 0;

	int posY = 160;
//	unsigned char deltaY;

	int velY = 0;
	engine_font_manager_draw_data( posY, 10, 5 );

	engine_font_manager_draw_data( velocityY[0], 10, 10 );
	engine_font_manager_draw_data( velY, 20, 10 );
	velY = do_jump( velY );
	engine_font_manager_draw_data( velY, 20, 12 );

	posY += velY;
	//test = fabsf( data );
	//test = myabs( data );
	engine_font_manager_draw_data( posY, 10, 15);
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}