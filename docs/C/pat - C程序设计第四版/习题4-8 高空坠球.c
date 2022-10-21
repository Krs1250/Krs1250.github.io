#include <stdio.h>

int main()
{
    int h,n;
    printf("输入初始高度(h), 反弹次数(n):");
    scanf("%d %d", &h, &n);

    double sum, final;
    sum = 0;
    final = h;
    for(int i=0; i<n; i++)
    {
        final /= 2.0;
        sum += (3.0*final);
    }
    printf("%.1lf %.1lf\n", sum, final);
}