#include <stdio.h>
#include <Windows.h>     //Sleep(ms)
int main()
{
    int cnt = 0;
    puts("输入秒数");
    scanf("%d", &cnt);
    while(cnt >= 0)
    {
        Sleep(1000);
        printf("%4.d\r", cnt);
        cnt--;
    }
    printf("计时结束\n");
    return 0;
}