#include <stdio.h>

int main()
{
	int x = 242000;
	int mask = 1;
	int t;
	
	while( mask <= x )
	{
		mask *= 10;
	}

	mask /= 10;
	
	do {
		t = x / mask;
		x %= mask;
		mask /= 10;
//		printf("%d ",t);

		printf("t=%d, x=%d, mask=%d\n", t, x, mask);
	} while ( mask > 0 );
	
	return 0;
}