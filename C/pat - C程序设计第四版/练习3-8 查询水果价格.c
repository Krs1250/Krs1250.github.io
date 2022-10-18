#include <stdio.h>

int main()
{
    int count = 0;
    while( count < 5 )
    {
        int n = 0;
        printf("\
        [1] apple\n\
        [2] pear\n\
        [3] orange\n\
        [4] grape\n\
        [0] exit\n\
        ");
        printf("请输入编号:\n");
        scanf("%d", &n);
        if( n == 1 )
        {
            printf("price = 3.00\n");
        }
        else if( n == 2 )
        {
            printf("price = 2.50\n");
        }
        else if( n == 3 )
        {
            printf("price = 4.10\n");
        }
        else if( n == 4 )
        {
            printf("price = 10.20\n");
        }
        else if( n == 0 )
        {
            break;
        }
        else
        {
            printf("price = 0.00\n");
        }
        count ++;
    }
}