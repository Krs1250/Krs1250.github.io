#include <stdio.h>

int main()
{
    int N;
    double sum = 0;
    printf("请输入正整数N");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        if( i%2 == 0)
        {
            sum += i*1.0/(2*i - 1) * (-1);
        }
        else
        {
            sum += i*1.0/(2*i - 1);
        }
        
    }
    printf("sum = %.3f", sum);
    return 0;
}