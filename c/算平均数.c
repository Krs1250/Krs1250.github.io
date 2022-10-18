#include <stdio.h>

int main()
{
	int number;
	int sum = 0;
	int count = 0;
	
	printf("请输入整数：");
		scanf("%d", &number);
	
	while(number != -1)
	{
		count ++;
		sum += number;
		printf("请输入整数：");
		scanf("%d", &number);
	}
	
	printf("平均数为：%f",1.0*sum/count);
	return 0;
}