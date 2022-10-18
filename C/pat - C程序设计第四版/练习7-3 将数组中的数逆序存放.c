#include <stdio.h>

int main()
{
	int n;
	printf("输入整数:");
	scanf("%d", &n);
	
	int number[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", (number+i));
//		printf("%d\n", *(number+i));
	}
	
	for(int i=(n-1); i>=0; i--)
	{
		printf("%d", *(number+i));	
		if(i!=0)
		{
			printf(" ");
		}
	}
}