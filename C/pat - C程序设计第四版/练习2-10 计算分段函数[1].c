#include <stdio.h>

int main()
{
	float x;
	
	scanf("%f", &x);
	
	if(x == 0)
	{
		printf("f(x) = 0");
	}
	else if (x != 0)
	{
		printf("f(x) = %.1f", 1/x);
	}
}