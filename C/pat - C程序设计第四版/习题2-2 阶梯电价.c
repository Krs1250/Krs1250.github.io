#include <stdio.h>

int main()
{
    int ele;
    double cost;
    printf("请输入用电量:（千瓦时）");
    scanf("%d", &ele);

    if(ele == 0)
    {
        cost = -1;
    }
    else if( ele <= 50)
    {
        cost = ele * 0.53;
    }
    else
    {
        cost = 50*0.53 + (ele-50)*0.58;
    }
    if(cost == -1)
    {
        printf("Invalid Value!");
    }
    else
    {
        printf("cost = %.2f", cost);
    }
    
}