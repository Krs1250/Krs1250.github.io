#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

typedef int DataType;
typedef struct SNode
{
    DataType data;
    struct SNode *next;
}SNode;
typedef SNode LinkStack;

/*栈初始化*/
LinkStack* InitStack(LinkStack *S)
{
    S = NULL;
    return S;
}

/*判别空栈*/
int StackEmpty(LinkStack *S)
{
    if(!S)
    {
        printf("栈为空\n");
        return True;
    }
    else
    {
        printf("栈不为空\n");
        return False;
    }
}

/*打印栈*/
int PrintStack(LinkStack *S)
{
    if(!S)
    {
        printf("栈打印失败，栈为空\n");
        return False;
    }
    else
    {
        while(S)
        {
            printf("%d->", S->data);
            S = S->next;
        }
        printf("\n");
        printf("栈打印成功\n");
        return True;
    }
}

/*取栈顶元素*/
DataType GetTop(LinkStack *S)
{
    if(!S)
    {
        printf("取栈顶元素失败，栈为空\n");
        return False;
    }
    else
    {
        printf("栈顶元素为：%d\n", S->data);
        return True;
    }
}

/*入栈*/
LinkStack* Push(LinkStack *S)
{
    int x;
    printf("输入数据：");
    fflush(stdin);
    scanf("%d", &x);

    SNode *temp;
    temp = (SNode *)malloc(sizeof(SNode));
    temp->data = x;
    temp->next = S;
    S = temp;
    printf("入栈成功\n");
    return S;
}

/*出栈*/
LinkStack* Pop(LinkStack *S)
{
    if(!S)
    {
        printf("出栈失败，栈为空\n");
        return False;
    }
    else
    {
        LinkStack *temp;
        temp = S;
        S = S->next;
        free(temp);
        printf("出栈成功\n");
        return S;
    }
}

void main()
{
    LinkStack *S;
    S = InitStack(S);
    
    int sign,exit=0;
    while(1)
    {
        printf("======================\n");
        printf("1 - 栈初始化\n");
        printf("2 - 判别空栈\n");
        printf("3 - 取栈顶元素\n");
        printf("4 - 入栈\n");
        printf("5 - 出栈\n");
        printf("6 - 打印栈\n");
        printf("0 - 退出\n");
        printf("=====================\n");
        printf("输入指令：");
        fflush(stdin);
        scanf("%d", &sign);

        switch(sign)
        {
            case 0:
                exit=1;break;
            case 1:
                InitStack(S);break;
            case 2:
                StackEmpty(S);break;
            case 3:
                GetTop(S);break;
            case 4:
                S = Push(S);break;
            case 5:
                S = Pop(S);break;
            case 6:
                PrintStack(S);break;
        }
        if(exit == 1)
        {
            break;
        }
    }
}