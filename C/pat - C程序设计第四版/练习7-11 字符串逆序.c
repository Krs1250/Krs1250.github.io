#include <stdio.h>

int main()
{
    char text[80];
    printf("输入一个字符串:");

    char temp;
    int count=0;
    for(int i=0; i<80; i++)
    {
        scanf("%c", &temp);
        if(temp == 10)
        {
            break;
        }
        text[i] = temp;
        count ++;
    }

    for(int i=count-1; i>=0; i--)
    {
        printf("%c", text[i]);
    }
}