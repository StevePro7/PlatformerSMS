#ifndef _ANIM_MANAGER_H_
#define _ANIM_MANAGER_H_

void engine_anim_manager_player_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyA_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyB_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyC_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyD_load( unsigned char index, unsigned int tile );

void engine_anim_manager_player_load_idle();
void engine_anim_manager_player_load_run( unsigned char move_type, unsigned char half_type );
void engine_anim_manager_enemyX_load_move_idle( unsigned char sprite_type );
void engine_anim_manager_enemyX_load_move_run( unsigned char sprite_type, unsigned char move_type, unsigned char half_type );
//void engine_anim_manager_enemyX_load_move_run_left( unsigned char sprite_type, unsigned char half );
//void engine_anim_manager_enemyX_load_move_run_rght( unsigned char sprite_type, unsigned char half );
//void engine_anim_manager_enemyX_load_stay_idle( unsigned char sprite_type, unsigned char index );

void engine_anim_manager_draw( unsigned char x, unsigned char y, unsigned int tile );

#endif//_ANIM_MANAGER_H_