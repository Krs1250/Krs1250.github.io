#include <stdio.h>

int main()
{
	int x;
	int isPrime = 1;
	
	scanf("%d", &x);
	
	for(int i=2; i<x; i++)
	{
		if( x%i == 0)
		{
//			printf("不是素数\n");
//			return 0;
			isPrime = 0;
		}
	}
	if(isPrime = 1)
	{
		printf("是素数\n");
		break;
	}
	else
	{
		printf("不是素数\n");
	}
	
	return 0;
}