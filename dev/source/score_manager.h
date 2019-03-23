#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#include "score_object.h"

// Global variable.
extern struct_score_object global_score_object;

void engine_score_manager_init();
void engine_score_manager_reset();
void engine_score_manager_update_lives( signed char delta );
void engine_score_manager_draw_heart();
void engine_score_manager_draw_lives();

#endif//_SCORE_MANAGER_H_