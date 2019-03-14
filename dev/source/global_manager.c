#include "global_manager.h"

// Custom function.
// https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
int myabs( int v )
{
	return v * ( ( v < 0 ) * ( -1 ) + ( v > 0 ) );
}