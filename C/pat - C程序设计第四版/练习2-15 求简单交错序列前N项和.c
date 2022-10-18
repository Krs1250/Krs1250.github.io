#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	printf("请输入正整数N:");
	scanf("%d", &N);
	
	float sum;
	for(float i = 0; i < N; i++)
	{
		sum += 1/(3*i + 1)*pow(-1, i);
	}
	
	printf("sum = %.3f", sum);
}