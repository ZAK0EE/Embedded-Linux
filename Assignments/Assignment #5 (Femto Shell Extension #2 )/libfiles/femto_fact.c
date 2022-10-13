#include <stdio.h>

int femto_fact()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	if(n < 0)
		return -1;

	unsigned long long fact = 1;

	int i;
	for(i = 1; i <= n; i++)
	{
		fact *= i;
	}
	
	printf("Result is: %llu\n", fact);
	
	return 1;
}
