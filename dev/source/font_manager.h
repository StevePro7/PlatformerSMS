#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

#define TEXT_ROOT	32		// 32 is " " in ASCII.
#define DATA_ROOT	16		// 16 is "0" (48=16+32)
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	7		// 7 placeholder

void engine_font_manager_draw_char( unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_text( unsigned char *text, unsigned char x, unsigned char y );
void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y );
void engine_font_manager_draw_data_ZERO( unsigned int data, unsigned char x, unsigned char y );

#endif//_FONT_MANAGER_H_