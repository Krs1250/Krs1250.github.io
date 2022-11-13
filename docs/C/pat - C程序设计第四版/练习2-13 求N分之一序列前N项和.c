#include <stdio.h>

int main()
{
	float N;
	
	printf("请输入正整数N：");
	scanf("%f", &N);
	
	float sum;
	
	for( float i = 1 ; i <= N ; i++)
	{
		sum += 1/i;
	}
	
	printf("%.6f", sum);
}