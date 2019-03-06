#ifndef _ENEMYK_OBJECT_H_
#define _ENEMYK_OBJECT_H_

typedef struct tag_struct_enemy_object
{
	unsigned char sx, sy;
	void( *draw )( void );

} struct_enemy_object;

#endif//_ENEMYK_OBJECT_H_