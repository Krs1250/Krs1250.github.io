#include <stdio.h>

int main()
{
    float x1,y1,x2,y2;
    printf("输入二维平面向量的分量:");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("(%.1f, %.1f)", x1+x2, y1+y2);
}