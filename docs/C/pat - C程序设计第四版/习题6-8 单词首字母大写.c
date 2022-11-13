#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    printf("输入给出一行字符:\n");
    scanf("%99[^\n]", text);

    // printf("a-z %d - %d\n", 'a', 'z');
    // printf("A-Z %d - %d\n", 'A', 'Z');
    // printf("%d\n",' ');

    int count=0;
    while((text[count]==' ')|| \
        ((text[count]>='A')&&(text[count]<='Z'))|| \
        ((text[count]>='a')&&(text[count]<='z')))
    {
        count+=1;
    }
    printf("%d\n", count);
    // printf("%c\n", text[3]='9');


    int key_first=1;
    int key_every=0;
    for(int i=0; i<count+1 ;i++)
    {
        if((key_first==1)&& \
        (((text[i]>='A')&&(text[i]<='Z'))||
        ((text[i]>='a')&&(text[i]<='z'))))
        {
            if((text[i]>='a')&&(text[i]<='z'))
            {
                text[i]-=32;
            }
            key_first=0;
        }
        else if(text[i] == ' ')
        {
            key_every = 1;
        }
        else if( (key_every==1)&& \
        (text[i]>='a')&&(text[i]<='z'))
         {
            text[i]-=32;
            key_every = 0;
         }
    }
    printf("%s",text);
}