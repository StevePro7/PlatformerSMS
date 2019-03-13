#include "delay_manager.h"

// Global variable.
struct_delay_object global_delay_object;

void engine_delay_manager_init()
{
	struct_delay_object *dObj = &global_delay_object;
	dObj->delay_delta = 0;
	dObj->delay_timer = 0;
}

void engine_delay_manager_load()
{
}

void engine_delay_manager_update()
{
}