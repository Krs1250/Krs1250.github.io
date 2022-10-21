#include <stdio.h>

int main()
{
	int n;
	printf("请输入非负整数n:");
	scanf("%d",  &n);
	
	int sum;
	int result;
	for(int i = 0; i <= n; i++)
	{
		result = 1;
		for(int j = 1; j <= i; j++)
		{
			result *= 3;
		}
		printf("pow(3,%d) = %d\n", i, result);
	}
}