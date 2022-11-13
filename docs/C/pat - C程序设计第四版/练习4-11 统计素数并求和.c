#include <stdio.h>

int main()
{
    int M,N;
    int count = 0;
    int sum = 0;
    
    printf("输入正整数M N");
    scanf("%d %d", &M, &N);

    for(int i=M; i<=N; i++)
    {
        int key = 1;
        for(int j=2; j<i; j++)
        {
            if( i%j == 0)
            {
                key = 0;
                break;
            }
        }
        if( key == 1)
        {
            count += 1;
            sum += i;
            // printf("%d\n", i);
        }
    }
    printf("%d %d\n", count, sum);
}