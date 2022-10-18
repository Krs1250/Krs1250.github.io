#include <stdio.h>

int main()
{
	int n,m;
	printf("输入右移位置m & 行列式n : ");
	scanf("%d %d", &m, &n);
	int matrix[n][n];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int add;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			add = j-m;
//			printf("|%d|", add);
			while(add<0)
			{
				add+=n;
			}
//			printf("%d %d\n", i,add);
			printf("%d ", matrix[i][add]);
		}
		printf("\n");
	}
}