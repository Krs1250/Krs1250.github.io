#include <stdio.h>

int sum1(int n, int m);
double sum2(int n, int m);

int main()
{
    int m,n;
    double sum=0;
    printf("请输入正整数m n");
    scanf("%d %d", &m, &n);
    
    printf("sum = %f\n", sum1(n, m) + sum2(n, m));
    return 0;
}

int sum1(int n, int m)
{
    // 求平方和
    int sum = 0;
    for(int i = m; i <= n; i++)
    {
        sum += i*i;
    }
    return sum;
}

double sum2(int n, int m)
{
    // 求倒数和
    double sum = 0;
    for(int i = m; i<= n; i++)
    {
        sum += 1.0/i;
    }
    return sum;
}