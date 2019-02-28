#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

typedef struct tag_struct_level_object
{
	unsigned char *collision_matrix;

} struct_level_object;

extern const unsigned char *leveldata[];
extern const unsigned char levelsize[];
extern const unsigned char levelbank[];

#endif//_LEVEL_OBJECT_H_