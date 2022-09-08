#include <stdio.h>
#include <string.h>

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

		printf("You said: %s\n", input);

		clear_stdin();

	}

	return 0;
}

