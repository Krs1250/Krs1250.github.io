#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a, &b);
	
	if( a < b)
	{     
		printf("fahr celsius\n");
		printf("%d %.1f \n", a, 5*(a-32)/9.0);
		printf("%d %.1f \n", b, 5*(b-32)/9.0);               
	}                               
	else            
	{
		printf("Invalid.");
	}
}