#include <stdio.h>

/*
    兔子对数/月 1 1 2 3 5 8 13 21 34
*/

int main()
{
    int N;
    printf("输入正整数N:");
    scanf("%d", &N);

    int count;
    int a,b,temp;
    a = 1;
    b = 1;
    temp = 0;
    if( N == 1 )
    {
        count = 1;
    }
    else
    {
        count = 2;
        while( b<N )
        {
            printf("month = %d, rab = %d\n", count, b);
            temp = a+b;
            a = b;
            b = temp;
            count += 1;
        }
        printf("%d", count);   
    }

    }