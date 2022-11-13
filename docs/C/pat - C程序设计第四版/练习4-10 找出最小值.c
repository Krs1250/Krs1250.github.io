#include <stdio.h>

int main()
{
    int n;
    int min;
    printf("输入正整数n\n");
    scanf("%d", &n);

    int temp;
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &temp);

        if( i == 0 )
        {
            min = temp;
        }
        else if( min > temp)
        {
            min = temp;
        }
    }
    printf("min = %d", min);
}