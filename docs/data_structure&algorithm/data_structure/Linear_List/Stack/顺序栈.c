#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

#define MAXSIZE 1000

typedef int DataType;
typedef struct
{
    DataType stack[MAXSIZE];
    int top;
}SeqStack;

/*栈初始化*/
SeqStack* InitStack(SeqStack *S)
{
    S = (SeqStack *)malloc(sizeof(SeqStack));
    if(!S)
    {
        printf("空间不足\n");
        return False;
    }
    else
    {
        S->top = -1;
        printf("栈初始化成功\n");
        return S;
    }
}

/*判别空栈*/
int StackEmpty(SeqStack *S)
{
    if(S->top == -1)
    {
        printf("栈为空栈\n");
        return False;
    }
    else
    {
        printf("栈不为空\n");
        return True;
    }
}

/*打印栈*/
int PrintStack(SeqStack *S)
{
    if(S->top == -1)
    {
        printf("栈表为空\n");
        return False;
    }
    else
    {
        int t=S->top;
        while(t!=-1)
        {
            printf("%d->", S->stack[t]);
            t --;
        }
        printf("\n");
        printf("栈打印成功\n");
        return True;

    }
}

/*取栈顶元素*/
DataType GetTop(SeqStack *S)
{
    if(S->top == -1)
    {
        printf("取元素失败，栈为空\n");
        return False;
    }
    else
    {
        printf("取元素成功，所取元素为%d\n", S->stack[S->top]);
        return S->stack[S->top];
    }
}

/*入栈*/
int Push(SeqStack *S)
{
    DataType x;
    printf("输入入栈元素：");
    fflush(stdin);
    scanf("%d", &x);

    if(S->top == MAXSIZE-1)
    {
        printf("入栈失败，栈是满的\n");
        return False;
    }
    else
    {
        S->top ++;
        S->stack[S->top] = x;
        printf("入栈成功\n");
        return True;
    }
}

/*出栈*/
int Pop(SeqStack *S)
{
    if(S->top == -1)
    {
        printf("出栈失败，栈是空的\n");
        return False;
    }
    else
    {
        S->top --;
        printf("出栈成功\n");
        return True;
    }
}

void main()
{
    SeqStack *S;
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
                Push(S);break;
            case 5:
                Pop(S);break;
            case 6:
                PrintStack(S);break;
        }
        if(exit == 1)
        {
            break;
        }
    }
}