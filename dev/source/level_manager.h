#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

#define COLS 15
#define ROWS 12

void engine_level_manager_load_levelX();
void engine_level_manager_load_level( const unsigned char *level, const unsigned char bank, const unsigned char size );
void engine_level_manager_load_index( const unsigned char index );
void engine_level_manager_draw_level_column( unsigned char column );
void engine_level_manager_draw_level_column_side( unsigned side_type, unsigned char column );
void engine_level_manager_draw_level();

extern unsigned char level_map[ ROWS * COLS ];
extern unsigned char tiles_map[ ROWS * COLS ];
extern unsigned char crash_map[ ROWS * COLS ];
extern unsigned char level_mat[ ROWS ][ COLS ];
extern unsigned char tiles_mat[ ROWS ][ COLS ];
extern unsigned char crash_mat[ ROWS ][ COLS ];

#endif//_LEVEL_MANAGER_H_