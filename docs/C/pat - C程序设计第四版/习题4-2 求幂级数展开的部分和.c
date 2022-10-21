#include <stdio.h>

double number(double x, int i);

int main()
{
    double x;
    printf("请输入x:");
    scanf("%lf", &x);

    double sum = 0;
    double temp = 1;
    for(int i=1; temp >= 0.00001; i++)
    {
        sum += temp;

        temp = number(x,i);
    }
    printf("%.4f\n", sum);
}

double number(double x, int i)
{
    double top = 1;
    double bottom = 1;

    for(int j = i; j > 0; j--)
    {
        top *= x;
        bottom *= j;
    }

    return top/bottom;
}