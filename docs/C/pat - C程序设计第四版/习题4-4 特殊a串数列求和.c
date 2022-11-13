#include <stdio.h>

int main()
{
    int a,n;
    int sum = 0;
    printf("输入正整数a和n");
    scanf("%d %d", &a, &n);

    int temp;
    for(int i=1; i<=n; i++)
    {
        temp = 1;
        temp *= a;
        for(int j=2; j<=i; j++)
        {
            temp *= 10;
            temp += a;
        }
        printf("temp = %d\n", temp);

        sum += temp;
    }
    printf("%d\n", sum);
}