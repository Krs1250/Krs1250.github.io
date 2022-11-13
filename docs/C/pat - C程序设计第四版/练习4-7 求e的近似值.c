#include <stdio.h>

double series_demo(int t);

int main()
{
    int n;
    double sum = 1;
    printf("输入非负整数n:\n");
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        sum += 1.0/series_demo(i);
    }
    printf("%.8lf", sum);
}

double series_demo(int t)
{
    int result = 1;
    for(int i=1; i<=t; i++)
    {
        result *= i;
    }
    return result;
} 