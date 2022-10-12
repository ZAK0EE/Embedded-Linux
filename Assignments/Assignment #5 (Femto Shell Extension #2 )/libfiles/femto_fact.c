unsigned long long femto_fact(int n)
{
	if(n < 0)
		return -1;

	unsigned long long fact = 1;

	int i;
	for(i = 1; i <= n; i++)
	{
		fact *= i;
	}
	
	return fact;
}
