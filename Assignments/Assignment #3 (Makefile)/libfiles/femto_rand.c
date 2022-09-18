#include <stdlib.h>
#include <time.h>

int femto_rand(void)
{
	srand(time(0));
	return rand();	
}
