#include "reset_manager.h"
#include "font_manager.h"

// Global variable.
struct_reset_object global_reset_object;

// Methods.
void engine_reset_manager_load( unsigned char frame, unsigned char screen )
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_frame = frame;
	ro->reset_screen = screen;

	engine_reset_manager_reset();
}

void engine_reset_manager_reset()
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_timer = 0;
	//engine_font_manager_draw_data( ro->reset_timer, 10, 10 );
}

unsigned char engine_reset_manager_update()
{
	struct_reset_object *ro = &global_reset_object;
	unsigned char test;

	ro->reset_timer++;
	//engine_font_manager_draw_data( ro->reset_timer, 10, 10 );
	test = ro->reset_timer >= ro->reset_frame;
	if( test )
	{
		ro->reset_timer = 0;
	}

	return test;
}