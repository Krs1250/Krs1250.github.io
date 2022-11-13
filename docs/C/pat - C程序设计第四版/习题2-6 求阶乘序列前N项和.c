#include <stdio.h>

int fact(int n);

int main()
{
    int N;
    int sum = 0;
    printf("请输入正整数N");
    scanf("%d", &N);

    for(int i = 1; i<=N; i++)
    {
        sum += fact(i);
    }

    printf("%d", sum);
}

int fact(int n)
{
    int result = 1;
    for(int i = 1; i<=n ; i++)
    {
        // printf("%d\n", i);
        result *= i;
    }
    return result;
}