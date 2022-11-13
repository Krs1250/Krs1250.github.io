#include <stdio.h>

int main()
{
    double run = 0.0;
    int wait = 0;
    int money = 0;

    scanf("%lf %d", &run, &wait);

    // 正常行驶
    if(run <= 3)
    {
        money = 10;
    }
    else if(run>3 && run<=10)
    {
        money = 10 + (run-3)*2;
    }
    else if(run>10)
    {
        money = 10 + (10-3)*2 + (run-10)*3;
    }

    // 临时停车
    if(wait >= 5)
    {
        money += (wait%5)*2; 
    }
    
    printf("%d\n", money);
}