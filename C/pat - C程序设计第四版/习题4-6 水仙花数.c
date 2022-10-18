#include <stdio.h>

int main()
{
    int N;

    printf("输入位数N:");
    scanf("%d", &N);

    int number = 1;
    for( int i=1; i<=N; i++)
    {
        number*=10;
    }

    for(int i=(number/10); i<number; i++)
    {
        int sum = 0;
        int temp = i;
        for(int j=1; j<=N; j++)
        {
            int sum_demo = 1;
            for(int k=1; k<=N; k++)
            {
                sum_demo *= (temp%10);
            }
            sum += sum_demo;
            temp /= 10;
        }
        // printf("%d\n", i);
        if(sum == i)
        {
            printf("%d\n", i);
        }
    }
}