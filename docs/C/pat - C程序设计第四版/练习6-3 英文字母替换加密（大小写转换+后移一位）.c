#include <stdio.h>
#include <string.h>

int main()
{
    printf("a - z = %d - %d\n", 'a', 'z');
    printf("A - Z = %d - %d\n", 'A', 'Z');
    char text[100];
    scanf("%s", text);
    for(int i=0; i<strlen(text); i++)
    {
        // 由于使用了strlen() 所以不可以使用空格
        if((int)text[i] <= 122 && (int)text[i]>= 97)
        {
            printf("%c", (int)text[i] - 31);
        }
        else if((int)text[i] <= 90 && (int)text[i]>= 65)
        {
            printf("%c", (int)text[i] + 33);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}