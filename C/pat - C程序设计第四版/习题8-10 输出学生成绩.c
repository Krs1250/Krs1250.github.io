#include <stdio.h>

int main()
{
    int N;
    printf("输入学生数量:");
    scanf("%d", &N);

    double number[N];
    for(int i=0; i<N; i++)
    {
        scanf("%lf", &number[i]); 
    }

    int max=0;
    int min=0;
    int sum = number[0];
    for(int i=1; i<N; i++)
    {
        sum += number[i];
        if(number[max]<number[i])
        {
            max = i;
        }

        if(number[min]>number[i])
        {
            min = i;
        }
    }
    printf("average = %.2lf\n", sum*1.0/N);
    printf("max = %.2lf\n", number[max]);
    printf("min = %.2lf\n", number[min]);
}