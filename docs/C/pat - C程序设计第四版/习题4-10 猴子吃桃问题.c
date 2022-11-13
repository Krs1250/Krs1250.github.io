#include <stdio.h>

int main()
{
    int N;
    printf("输入正整数N:");
    scanf("%d", &N);

    int pitch;
    pitch = 1;

    for(int i = N-1; i>0; i--)
    {
        pitch += 1;
        pitch *= 2;
    }
    printf("%d\n", pitch);
}