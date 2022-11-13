#include <stdio.h>

int main()
{
    int hour,minute,second;
    printf("输入起始时间:");
    scanf("%d:%d:%d", &hour, &minute, &second);

    int add;
    printf("再过时间值(<60):");
    scanf("%d", &add);

    second+=add;
    if(second>=60)
    {
        second -= 60;
        minute += 1;
        if(minute==60)
        {
            minute -= 60;
            hour += 1;
            if(hour==24)
            {
                hour -= 24;
            }
        }
    }
    printf("%d:%d:%d\n", hour, minute, second);
}