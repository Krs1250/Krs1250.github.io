#include <stdio.h>

int main()
{
    char text[80];
    printf("输入字符串:");

    char temp;
    int count;
    for(int i=0; i<80; i++)
    {
        scanf("%c", &temp);
        if(temp == 10)
        {
            break;
        }
        text[i] = temp;
        if(temp != 'A' \
        && temp != 'E' \
        && temp != 'I' \
        && temp != 'O' \
        && temp != 'U' \
        && temp <= 90 \
        && temp >= 65)
        {
            count += 1;
        }

    }
    printf("%d\n", count);
}