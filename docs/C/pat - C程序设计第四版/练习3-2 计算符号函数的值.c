#include <stdio.h>

int main()
{
    int n;
    int result = 0;
    printf("请输入整数n:");
    scanf("%d", &n);

    if( n<0)
    {
        result = -1;
    }
    else if( n == 0)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    printf("sign(%d) = %d", n, result);
}