#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	float result;
	
	printf("请输入实数x：");
	scanf("%f",&x);
	
	if(x >= 0)
	{
		result = sqrt(x);
	}
	else if (x < 0)
	{
		result = pow(x, 2) + 2*x + 1/x;
	}
	
	printf("f(%.2f) = %.2f", x, result);
}