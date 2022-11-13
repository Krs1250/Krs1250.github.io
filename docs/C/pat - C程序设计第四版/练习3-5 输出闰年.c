#include <stdio.h>

int main()
{
    int N;
    printf("输入截至年份:");
    scanf("%d", &N);

    for(int i = 2001; i <= N; i++)
    {
        if( i%4 == 0)
        {
            printf("%d\n", i);
        }
    }
}