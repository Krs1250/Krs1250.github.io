#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);

    double exceed = 0;
    if( a>b )
    {
        exceed = 1.0*(a-b)/b;
    }

    if( exceed >= 0.1 && exceed < 0.5 )
    {
        printf("Exceed %.f%%. Ticket 200\n", exceed*100);
    }
    else if( exceed >= 0.5 )
    {
        printf("Exceed %.f%%. License Revoked\n", exceed*100);
    }
    else
    {
        printf("OK");
    }
}