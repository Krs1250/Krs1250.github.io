#include <stdio.h>

int main()
{
    // 接收待查找字符
    char search;
    printf("请输入待查找字符:");
    scanf("%c", &search);

    // -- 用于接收多余的换行符
    char a;
    scanf("%c", &a);

    // 接受待查找字符串
    char text[80];
    char temp;
    int result= -1;
    printf("请输入字符串(回车结束):");
    for(int i=0; i<80; i++)
    {
        scanf("%c", &temp);
        // printf("%d - %d\n", temp, search);
        if(temp == 10)
        {
            break;
        }
        else if(temp == search && result == (-1))
        {
            result = i+1;
        }
        text[i] = temp;
    }
    if(result == (-1))
    {
        printf("Not Found\n");
    }
    else
    {
        printf("%d\n", result);
    }
}