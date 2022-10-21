#include <stdio.h>

int main()
{
	int count=0;
	int sum=0;
	int a,b;
	scanf("%d %d",&a,&b);
	for( int i=a; i<=b ;i++)
	{
		int isPrime = 1;
		for( int j=2; j<i ; j++)
		{
			if( i%j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if(isPrime == 1)
		{
			count += 1;
			sum += i;
		}
	}
	
	printf("%d %d",count,sum);
	return 0;
	
}