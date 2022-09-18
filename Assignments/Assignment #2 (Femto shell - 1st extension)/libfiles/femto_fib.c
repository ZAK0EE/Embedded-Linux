#include <stdio.h>

void femto_fib(int count)
{

	int first_term = 0, second_term = 1, next_term;

	int i;
	for ( i = 0 ; i < count ; i++ )
	{
		if ( i <= 1 )
			next_term = i;
		else
		{
			next_term = first_term + second_term;
			first_term = second_term;
			second_term = next_term;
		}
		printf("%d",next_term);

		if(i != count - 1)
			printf(", ");
	}

	printf("\n");

}
