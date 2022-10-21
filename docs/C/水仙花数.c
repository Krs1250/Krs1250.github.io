#include <stdio.h>

int main()
{
	int x = 3;
	int max = 1;
	
	for(int i=1; i <= x; i++)
	{
		max *= 10;
	}
	for(int i=max/10; i <= max-1 ; i++)
	{
		int sum = 0;
		int num = i;
		while( num > 0 )
		{
			sum += (num%10)*(num%10)*(num%10);
			num /= 10;
		}
//		printf("%d\n", sum);
		if( sum == i )
		{
			printf("%d\n", i);
		}
	}
}