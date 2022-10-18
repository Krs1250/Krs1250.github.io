#include <stdio.h>

int main()
{
    int M,N;
    printf("两个正整数M和N:");
    scanf("%d %d", &M, &N);

    int min,max;
    if( M > N )
    {
        min = N;
        max = M;
    }
    else
    {
        min = M;
        max = N;
    }

    // 最大公因数
    int max_gys = 1;
    for(int i=2; i<=min; i++)
    {
        // printf("%d\n", i);
        if( M%i==0 && N%i==0 )
        {
            max_gys = i;
        }
    }
    printf("%d ", max_gys);

    // 最小公倍数
    int min_gbs = 10;
    for(int i=max; ;i++)
    {
//    	printf("%d\n", i);
        if( i%M==0 && i%N==0 )
        {
            min_gbs = i;
            break;
        }
    }
    printf("%d", min_gbs);
}