#include <stdio.h>
#include <string.h>

int main()
{
    int letter,blank,digit,other;
    letter = 0,
    blank = 0,
    digit = 0;
    other = 0;

    for( int i = 0; i < 10; i++ )
    {
        char a;
        // printf("请输入字符：");
        scanf("%c", &a);
        // printf("%c = %d\n", a, a);
        if( (65 <= a &&  a <= 90) || (97 <= a && a <= 122) )
        {
            letter += 1;
            // printf("letter\n");
        }
        else if( 48 <= a && a <= 57 )
        {
            digit += 1;
            // printf("digit\n");
        }
        else if( a == 32 || a == 10 )
        {
            blank += 1;
            // printf("blank\n");
        }
        else
        {
            other += 1;
            // printf("other\n");
        }
    }

    printf("letter = %d\n", letter);
    printf("blank = %d\n", blank);
    printf("digit = %d\n", digit);
    printf("other = %d\n", other);
}