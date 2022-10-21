#include <stdio.h>

int main()
{
    int N;
    printf("输入正整数N");
    scanf("%d", &N);
    
    double sum = 0;
    int a = 2;
    int b = 1;
    int c,d;
    for(int i=1; i<=N ; i++)
    {
        if( i%2 == 1)
        {
            sum += a*1.0/b;
            c = a+b;
            d = a;
        }
        else
        {
            sum += c*1.0/d;
            a = c+d;
            b = c;
        }
    }
    printf("%.2lf\n", sum);
}