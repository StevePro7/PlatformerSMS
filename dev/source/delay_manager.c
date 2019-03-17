#include "delay_manager.h"
#include "font_manager.h"

// Global variable.
struct_delay_object global_delay_object;

void engine_delay_manager_load( unsigned int delay )
{
	struct_delay_object *dObj = &global_delay_object;
	dObj->delay_delay = delay;
	dObj->delay_timer = 0;

	engine_font_manager_draw_data( dObj->delay_delay, 10, 11 );
	engine_font_manager_draw_data( dObj->delay_timer, 10, 12 );
}

unsigned char engine_delay_manager_update()
{
	struct_delay_object *dObj = &global_delay_object;
	dObj->delay_timer++;

	engine_font_manager_draw_data( dObj->delay_timer, 10, 12 );
	return dObj->delay_timer >= dObj->delay_delay;
}