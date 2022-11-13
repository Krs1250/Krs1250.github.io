#include <stdio.h>

double fact(int n);

int main()
{
    int n, m;
    double result = 1;
    printf("请输入元素n m:");
    scanf("%d %d", &n, &m);

    result = fact(n)/(fact(m)*fact(n-m));
    printf("result = %f/n", result);
}

double fact(int n)
{
    int result = 1;
    for(int i = n; i > 0; i--)
    {
        result *= i;
    }
    return result;
}