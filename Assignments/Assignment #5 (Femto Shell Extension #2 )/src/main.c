#include <stdio.h>
#include <string.h>

#include <femto_rand.h>
#include <femto_fact.h>
#include <femto_fib.h>

void clear_stdin()
{
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) { }
}


int main()
{
	char input[101];
	while(1)
	{
		printf("Enter your command > ");
		scanf(" %100[^\n]s", input);

		if(strcmp(input, "exit") == 0)
		{
			printf("Good bye!\n");
			break;
		}
		else if(strcmp(input, "rand") == 0)
		{
			printf("%d\n", femto_rand());
		}
		else if(strcmp(input, "fact") == 0)
		{
			int fact_n;
			printf("Enter a number: ");
			scanf("%d", &fact_n);

			printf("Result is: %llu\n", femto_fact(fact_n));
		}
		else if(strcmp(input, "fib") == 0)
		{
			int fib_n;
			printf("Enter a number: ");
			scanf("%d", &fib_n);
			
			printf("The sequence is: ");
			femto_fib(fib_n);
		}
		else
		{
			printf("You said: %s\n", input);
		}


		clear_stdin();

	}

	return 0;
}

