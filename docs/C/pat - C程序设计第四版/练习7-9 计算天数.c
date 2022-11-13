#include <stdio.h>

int main()
{
    char date[10];
    printf("请输入日期:");
    for(int i=0; i<10; i++)
    {
        scanf("%c", &date[i]);
    }


    //  字符串分段
    int year=0;
    int month=0;
    int day=0;
    for(int i=0; i<10; i++)
    {
        if(i>=0 && i<4)
        {
            if(year != 0)
            {
                year*=10;
            }
            year += date[i]-'0';
        }
        else if(i>=5 && i<7)
        {
            if(month != 0)
            {
               month*=10;
            }
            month += date[i]-'0';
        }
        else if(i>=8 && i<10)
        {
            if(day != 0)
            {
                day*=10;
            }
            day += date[i]-'0';
        }
    }

    // printf("%d %d %d", year, month, day);

    //  判断闰年
    int run = 0;
    if((year%4==0 && year%100!=0) || (year%400==0))
    {
        run = 1;
    }

    // 天数计算
    int result=0;
    for(int i=1; i<month; i++)
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
        {
            result += 31;
        }
        else if(i==4||i==6||i==9||i==11)
        {
            result += 30;
        }
        else if(i==2 && run == 1)
        {
            result += 29;
        }
        else if(i==2 && run == 0)
        {
            result += 28;
        }
    }
    result += day;

    printf("%d\n", result);
}