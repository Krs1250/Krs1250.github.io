#include <stdio.h>

typedef struct
{
    char name[80];
    float price;
}book;

int main()
{
    int n;
    printf("输入书本数目:");
    scanf("%d", &n);

    book u1[n];
    char temp_name;
    for(int i=0; i<n; i++)
    {
    	// 用于接收多的的回车
    	int temp;
    	scanf("%d", &temp);
        for(int j=0; j<80; j++)
        {
        	scanf("%c", &temp_name);
        	if(temp_name == 10)
        	{
        		break;
			}
			u1[i].name[j] = temp_name;
		}
        scanf("%f", &u1[i].price);
    }

    int max = 0;
    int min = 0;
    for(int i=1; i<n; i++)
    {
        if(u1[i].price > u1[max].price)
        {
            max = i;
        }
        if(u1[i].price < u1[min].price)
        {
            min = i;
        }
    }
    printf("%.2f, %s\n", u1[max].price, u1[max].name);
    printf("%.2f, %s\n", u1[min].price, u1[min].name);
}