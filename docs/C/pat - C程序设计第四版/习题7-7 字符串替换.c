#include <stdio.h>

int main()
{
    char text[80];
    printf("输入字符串:");

    char temp;
    int count = 0;
    for(int i=0; i<80; i++)
    {
        scanf("%c", &temp);
        if(temp == 10)
        {
            break;
        }
        text[i] = temp;
        count += 1;
    }

    for(int i=0; i<count; i++)
    {
        if(text[i]<=90 && text[i]>=65)
        {
            text[i] = (90 - (text[i] - 65));
        }
    }
    printf("%s\n", text);
}