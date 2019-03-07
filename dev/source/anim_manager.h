#ifndef _ANIM_MANAGER_H_
#define _ANIM_MANAGER_H_

void engine_anim_manager_player_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyA_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyB_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyC_load( unsigned char index, unsigned int tile );
void engine_anim_manager_enemyD_load( unsigned char index, unsigned int tile );

void engine_anim_manager_draw( unsigned char x, unsigned char y, unsigned int tile );

#endif//_ANIM_MANAGER_H_