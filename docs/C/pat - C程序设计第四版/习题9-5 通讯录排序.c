#include <stdio.h>

typedef struct
{
    char name[10];
    int birthday;
    char phone[17];
}friends;

int main()
{
    int n;
    printf("输入人数：");
    scanf("%d", &n);
    friends people[n];

    int temp;
    scanf("%d",&temp);

    for(int i=0; i<n; i++)
    {
        scanf("%s", people[i].name);
        scanf("%d", &people[i].birthday);
        scanf("%s", people[i].phone);
        
    }

    int min;
    for(int i=0; i<n; i++)
    {
        min = i;
        for(int j=0; j<n; j++)
        {
            if(i == j)
            {
                continue;
            }
            // printf("|||%d %d\n", people[min].birthday , people[j].birthday);
            if(people[min].birthday > people[j].birthday)
            {
                min = j;
            }
        }

        printf("%s %d %s\n", people[min].name, people[min].birthday, people[min].phone);
        people[min].birthday = 99999999;
    }
}