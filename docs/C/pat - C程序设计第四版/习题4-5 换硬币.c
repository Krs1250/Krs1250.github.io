#include <stdio.h>

int main()
{
    int fen5,fen2,fen1;
    int x;
    int count = 0;
    printf("输入待换零钱数额x:");
    scanf("%d", &x);

    for(int i=1; i*5<x; i++)
    {
        for(int j=1; j*2<x; j++)
        {
            for(int k=1; k*1<x; k++)
            {
                if(i*5+j*2+k*1 == x)
                {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, i+j+k);
                    count += 1;
                }
            }
        }
    }
    printf("count = %d\n", count);
}