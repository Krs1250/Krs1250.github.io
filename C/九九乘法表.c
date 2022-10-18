#include <stdio.h>

int main()
{
	for( int i=1 ; i <= 19; i++)
	{
		for( int j=1 ; j <= i; j++)
		{
			printf("%d*%d=%d",j ,i ,i*j);
			if( i == j)
			{
				printf("\n");
			}
			else
			{
				printf("  ");
			}
		}
	}
}