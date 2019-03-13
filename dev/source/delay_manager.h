#ifndef _DELAY_MANAGER_H_
#define _DELAY_MANAGER_H__

#include "delay_object.h"

void engine_delay_manager_init();
void engine_delay_manager_load();
void engine_delay_manager_update();

// Global variable.
extern struct_delay_object global_delay_object;

#endif//_DELAY_MANAGER_H_