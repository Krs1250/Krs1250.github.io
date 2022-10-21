#include <stdio.h>

int main()
{
    int n;
    printf("输入一个正的奇数n:");
    scanf("%d", &n);

    // 上部分
    for(int i=1; i<=n/2; i++)
    {
        // 空格 
        for(int j=1; j<=n/2-i+1; j++)
        {
            printf("  ");
        }
        // *
        for(int k=n/2-i+2; k<=n/2+i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    // 中间部分
    for(int i=1; i<=n; i++)
    {
        printf("* ");
    }
    printf("\n");
    // 下部分
        for(int i=n/2; i>=1; i--)
    {
        // 空格 
        for(int j=1; j<=n/2-i+1; j++)
        {
            printf("  ");
        }
        // *
        for(int k=n/2-i+2; k<=n/2+i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}