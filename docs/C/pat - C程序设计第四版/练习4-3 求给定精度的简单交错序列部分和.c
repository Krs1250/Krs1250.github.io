#include <stdio.h>

int main()
{
    double eps;
    double sum;

    printf("请输入正实数eps:");
    scanf("%lf", &eps);

    double number = 1;
    int i;
    for( i = 1; number >= eps; i++ )
    {
        printf("%d %f\n", i, number);
        if( i%2 == 0 )
        {
            sum-= number;
        }
        else
        {
            sum+=number;
        }
        number = 1.0/(3*i+1);
    }
    // if( i%2 == 0 )
    // {
    //     sum-= number;
    // }
    // else
    // {
    //     sum+=number;
    // }

    printf("number = %lf\n", number);
    printf("sum = %.6lf", sum);
}