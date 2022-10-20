#include <stdio.h>

int main()
{
    int N;
    printf("输入矩阵阶数(N):");
    scanf("%d", &N);

    int matrix[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int key;
    int a,b;
    a = -1;
    b = -1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            // printf("%d\n", matrix[i][j]);
            key = 1;
            // 行判断
            for(int m=0; m<N; m++)
            {
                if(m == j)
                {
                    continue;
                }
                if(matrix[i][m] > matrix[i][j])
                {
                    key = 0;
                    break;
                }
            }
            if(key != 0)
            {
                // 列判断
                for(int m=0; m<N; m++)
                {
                    if(m == i)
                    {
                        continue;
                    }
                    if(matrix[m][j] < matrix[i][j])
                    {
                        key = 0;
                        break;
                    }
                }
            }
            else{
                continue;
            }
            if(key != 0)
            {
                a = i;
                b = j;
            }

        }
    }
    if(a == -1 || b == -1)
    {
        printf("NONE");
    }
    else
    {
        printf("%d %d", a, b);
    }
}