#include <stdio.h>

int main()
{
    int point;
    scanf("%d", &point);

    if( point >= 90)
    {
        printf("A");
    }
    else if( point >= 80 && point < 90 )
    {
        printf("B");
    }
    else if( point >= 70 && point < 80 )
    {
        printf("C");
    }
    else if( point >= 60 && point < 70 )
    {
        printf("D");
    }
    else
    {
        printf("E");
    }
    return 0;
}