#include <stdio.h>

int main()
{
    int T;
    printf("出入待测矩阵个数(T):");
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        int n;
        printf("输入矩阵的阶数(n):");
        scanf("%d", &n);

        int matrix[n][n];
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                scanf("%d", &matrix[j][k]);
            }
        }

        // 判断是否为上三角
        int key=1;
        for(int j=1; j<n; j++)
        {
            for(int k=0; k<j; k++)
            {
                if(matrix[j][k] != 0)
                {
                    key = 0;
                }
            }
        }

        if(key == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

}