#include <stdio.h>

int main()
{
	int F;
	int C;
	
	printf("请输入华氏温度：");
	scanf("%d", &F);
	C =5*(F-32)/9;
	
	printf("fahr = %d, celsius = %d", F, C);
}
