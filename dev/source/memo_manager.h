#ifndef _MEMO_MANAGER_H_
#define _MEMO_MANAGER_H_

void engine_memo_manager_init();
void engine_memo_manager_draw( unsigned char left, unsigned char wide );

void engine_memo_manager_draw_level( const unsigned char world, const unsigned char round );
void engine_memo_manager_draw_pass( unsigned char perfect );
void engine_memo_manager_draw_gems();
void engine_memo_manager_draw_dead();
void engine_memo_manager_draw_cont();
void engine_memo_manager_draw_over();

//void engine_memo_manager_wipe_level();

#endif//_MEMO_MANAGER_H_