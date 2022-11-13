#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int a,b,c;
	int count = 0;
	
	for( a = x ; a <= x+3 ; a++ )
	{
		for ( b = x ; b <= x+3 ; b++ )
		{	
			if( b == a)
			{
				continue;
			}
			for ( c = x ; c <= x+3 ; c++)
			{
				if ( c == b )
				{
					continue;
				} else if ( c == a )
				{
					continue;
				}
//				printf("%d", a*100 + b*10 + c);
				printf("%d%d%d", a, b, c);
				count += 1;
				if( count == 6 )
				{
					count = 0;
					printf("\n");
				} else
				{
					printf(" ");
				}
			}
		}
	}
	return 0;
}