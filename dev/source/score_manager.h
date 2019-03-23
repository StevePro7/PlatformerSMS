#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#include "score_object.h"

// Global variable.
extern struct_score_object global_score_object;

void engine_score_manager_init( unsigned char difficulty );
void engine_score_manager_reset();
void engine_score_manager_update_gems();
void engine_score_manager_update_lives( signed char delta );
void engine_score_manager_draw_heart();
void engine_score_manager_draw_lives();
void engine_score_manager_draw_score( unsigned char x, unsigned char y );

#endif//_SCORE_MANAGER_H_