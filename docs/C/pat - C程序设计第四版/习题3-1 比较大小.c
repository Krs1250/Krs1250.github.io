#include <stdio.h>

int main()
{
    int a,b,c;
    int temp;
    printf("输入三个数字");
    scanf("%d %d %d", &a,&b,&c);

    if( a>b )
    {
        if( b>c )
        {
            printf("c->b->a");
        }
        else if( b<c )
        {
            if( a>c )
            {
                printf("b->c->a");
            }
            else if( a<c )
            {
                printf("b->a->c");
            }
        }
        else if( b==c )
        {
            printf("b--c->a");
        }
    }
    else if( a<b )
    {
        if( b>c )
        {
            if( a>c )
            {
                printf("c->a->b");
            }
            else if( a<c )
            {
                printf("a->c->b");
            }
            else if( a==c )
            {
                printf("c--a->b");
            }
        }
        else if( b<c )
        {
            printf("a->b->c");
        }
        else if( b==c )
        {
            printf("a->b--c");
        }
    }
    else if( a==b )
    {
        if( a>c )
        {
            printf("c->a--b");
        }
        else if( a<c )
        {
            printf("a--b->c");
        }
        else if( a==b )
        {
            printf("a--b--c");
        }
    }
}