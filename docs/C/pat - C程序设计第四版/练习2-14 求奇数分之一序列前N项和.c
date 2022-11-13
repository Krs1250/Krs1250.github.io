#include <stdio.h>

int main()
{
	int N;
	printf("请输入正整数N:");
	scanf("%d", &N);
	
	float sum;
	
	for(float i = 1; i <= N; i++)
	{
		sum += 1/(2*i - 1);
	}
	
	printf("sum = %.6f", sum);
}