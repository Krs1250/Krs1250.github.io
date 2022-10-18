#include <stdio.h>

int main()
{
	int n;
	printf("输入矩阵阶数n:");
	scanf("%d", &n);
	
	// 为矩阵赋值
	int matrix[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// 求和
	int result=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{ 
//			printf("%d %d: \n",i ,j);
//			printf("%d\n", matrix[i][j]);
			if(((n-i-1)==j) || (i==(n-1)) || (j==(n-1)))
			{
				continue;
			}
			else
			{
//				printf("%d\n", matrix[i][j]);
				result += matrix[i][j];
			}
		}
	}
	printf("%d", result);
}