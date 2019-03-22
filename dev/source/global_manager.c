#include "global_manager.h"

// Global values.
unsigned char *count_text[] =
{
	"01",
	"02",
	"03",
	"04",
	"05",
	"06",
	"07",
	"08",
	"09",
	"10",
};

// Custom function.
// https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
int myabs( int v )
{
	return v * ( ( v < 0 ) * ( -1 ) + ( v > 0 ) );
}