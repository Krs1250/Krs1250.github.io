#include <stdio.h>

int main()
{
    int n;
    printf("输入整数个数n:");
    scanf("%d", &n);

    int text[n];
    int temp;
    printf("输入数列数字:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &text[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(text[i]<text[j])
            {
                temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d", text[i]);
        if(i != n-1)
        {
            printf(" ");
        }
    }
    printf("\n");

}