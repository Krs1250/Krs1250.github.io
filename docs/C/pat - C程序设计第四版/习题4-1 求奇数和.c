#include <stdio.h>

int main()
{
    int sum = 0;
    while( 1 )
    {
        int temp;
        // printf("val:");
        scanf("%d", &temp);

        if( temp < 0 || temp == 0 )
        {
            // printf("exit");
            break;   
        }
        else
        {
            if( temp%2 != 0 )
            {
                sum += temp;
            }
        }

        
    }
    printf("%d\n", sum);
    
}