#include <stdio.h>

int main()
{
	int count = 0;
	for(int x=1; count < 50; x++)
	{
		int isPrime = 1;

		
		for (int i=2; i<x; i++)
		{
			if (x%i == 0)
			{
				isPrime = 0;
				break;
			}
		}
		
		if ( isPrime == 1)
		{
			printf("%d ", x);
			count ++;
		}
	}
	return 0;
}