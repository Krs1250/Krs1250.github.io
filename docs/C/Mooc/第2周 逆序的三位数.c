#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	
	int a1 = a/100;
	int a2 = (a - a1*100)/10;
	int a3 = a%10;
	
	printf("%d", a1 + a2*10 + a3*100);
	
	return 0;
}