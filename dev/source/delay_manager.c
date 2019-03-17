#include "delay_manager.h"

// Global variable.
struct_delay_object global_delay_object;

void engine_delay_manager_load( unsigned int delay )
{
	struct_delay_object *dObj = &global_delay_object;
	dObj->delay_delay = delay;
	dObj->delay_timer = 0;
}

unsigned char engine_delay_manager_update()
{
	struct_delay_object *dObj = &global_delay_object;
	unsigned char test;

	dObj->delay_timer++;
	test = dObj->delay_timer >= dObj->delay_delay;
	if( test )
	{
		dObj->delay_timer = 0;
	}

	return test;
}