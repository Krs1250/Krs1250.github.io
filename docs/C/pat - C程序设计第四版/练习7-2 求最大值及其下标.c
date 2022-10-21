#include <stdio.h>

int main()
{
	int n;
	printf("输入整数:");
	scanf("%d", &n);
	
	int max, max_i;
	int temp = 0;
	for(int i=0; i<n; i++)
	{
		printf("i = %d\n", i);
		scanf("%d", &temp);
		
		if(i==0)
		{
			max = temp;
			max_i = i;
		}
		else if(temp > max)
		{
			max = temp;
			max_i = i;
		}
	}
	printf("%d %d", max, max_i);
}