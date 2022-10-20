#include <stdio.h>

int main()
{
    int N;
    printf("输入整数个数N:");
    scanf("%d", &N);

    int number[10]={0,0,0,0,0,0,0,0,0,0};
    int a,temp;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        temp = a;
        while(a>0)
        {
            temp=a%10;
            number[temp]+=1;
            a/=10;
            temp=a;
        }
    }
    
    // 确定最多数字个数
    int max = 0;
    for(int i=1; i<10; i++)
    {
        if(number[max]<number[i])
        {
            max = i;
        }
        // printf("%d - %d\n", i, number[i]);
    }
    printf("%d:", number[max]);

    // 最多数字
    for(int i=0; i<10; i++)
    {
        if(number[i] == number[max])
        {
            printf(" %d", i);
        }
    }
}