#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int digit;
	
	
	digit = x%10;
	x /= 10;
	
	return 0;
}