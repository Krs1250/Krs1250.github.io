#include <stdio.h>

int main()
{
    char words[5][80];
    int size[5];
    printf("开始输入 * 5:");

    int temp;
    for(int i=0; i<5; i++)
    {
        size[i] = 0;
        for(int j=0; j<80; j++)
        {
            scanf("%lc", &temp);
            if(temp == 10|| temp == ' ')
            {
                break;
            }
            words[i][j] = temp;
            size[i] += temp;
        }
        
    }
    

    printf("After sorted:\n");
    int min;
    for(int i=0; i<5; i++)
    {
        min = i;
        for(int j=0; j<5; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(size[min]>size[j])
            {
                min = j;
            }
        }
        printf("%s\n", words[min]);
        size[min] = 9999999;
    }


}