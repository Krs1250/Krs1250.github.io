#include <stdio.h>

int main()
{
    int N;
    int temp;
    int A,B,C,D,E;
    A=0,B=0,C=0,D=0,E=0;

    printf("请输入学生数(N):");
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &temp);
        if( temp>= 90)
        {
            A += 1;
        }    
        else if( temp<90 && temp >=80 )
        {
            B += 1;
        }
        else if( temp<80 && temp >=70 )
        {
            C += 1;
        }
        else if( temp<70 && temp >=60 )
        {
            D += 1;
        }
        else if( temp<60 )
        {
            E += 1;
        }
    }
    printf("%d %d %d %d %d", A, B, C, D, E);
}