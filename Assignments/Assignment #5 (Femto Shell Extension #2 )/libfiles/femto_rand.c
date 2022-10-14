#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int femto_rand(void)
{
	srand(time(0));
	printf("%d\n", rand());
	return 1;	
}
