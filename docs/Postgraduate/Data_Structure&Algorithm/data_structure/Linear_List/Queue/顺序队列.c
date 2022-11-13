#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

#define MAXSIZE 20

typedef int DataType;
typedef struct
{
    int front;
    DataType Queue[MAXSIZE];
    int rear;
} SeqQueue;

/*队列初始化*/
SeqQueue* InitQueue(SeqQueue *Q)
{
    Q = (SeqQueue *)malloc(sizeof(SeqQueue));
    Q->front = Q->rear = 0;
    printf("队列初始化成功\n");
    return Q;
}

/*判断队列为空*/
int QueueEmpty(SeqQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("队列为空\n");
        return True;
    }
    else
    {
        printf("队列不为空\n");
        return False;
    }
}

/*打印队列*/
int PrintQueue(SeqQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("打印队列失败，对列为空\n");
        return False;
    }
    else
    {
        int cur;
        cur = Q->front;
        while((cur+1)%MAXSIZE != Q->front)
        {
            printf("%d->", Q->Queue[cur]);
            cur = (cur+1)%MAXSIZE;
        }
        printf("\n");
        printf("打印队列成功\n");
        return True;
    }
}

/*取队头元素*/
DataType GetTop(SeqQueue *S)
{
    if(S->front == S->rear)
    {
        printf("取队头元素失败，队列为空\n");
        return False;
    }
    else
    {
        printf("取队头元素成功，元素为：%d\n",S->Queue[S->front]);
        return True;
    }
}

/*入队*/
int EnQueue(SeqQueue *Q)
{
    int x;
    printf("输入数据：");
    fflush(stdin);
    scanf("%d", &x);

    if((Q->rear+1)%MAXSIZE == Q->front)
    {
        printf("入队失败，队列满\n");
        return False;
    }
    else
    {
        Q->Queue[Q->rear] = x;
        Q->rear = (Q->rear+1)%MAXSIZE;
        printf("入队成功\n");
        return True;
    }
}

/*出队*/
DataType DeQueue(SeqQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("出队失败，队列为空\n");
        return False;
    }
    else
    {
        int x;
        x = Q->Queue[Q->front];
        Q->Queue[Q->front] = 0;
        Q->front = (Q->front+1)%MAXSIZE;
        printf("出队成功，出队元素为：%d\n", x);
        return x;
    }
}

void main()
{
    SeqQueue *Q;
    Q = InitQueue(Q);

    while(1)
    {
        int sign, exit=0;
        printf("=====================\n");
        printf("1 - 初始化队列\n");
        printf("2 - 判断队空\n");
        printf("3 - 打印队列\n");
        printf("4 - 取队头元素\n");
        printf("5 - 入队\n");
        printf("6 - 出队\n");
        printf("0 - 退出\n");
        printf("=====================\n");
        printf("输入指令：");
        fflush(stdin);
        scanf("%d", &sign);

        switch(sign)
        {
            case 0:
                exit = 1;break;
            case 1:
                InitQueue(Q);break;
            case 2:
                QueueEmpty(Q);break;
            case 3:
                PrintQueue(Q);break;
            case 4:
                GetTop(Q);break;
            case 5:
                EnQueue(Q);break;
            case 6:
                DeQueue(Q);break;
        }
        if(exit==1)
        {
            break;
        }
    }
}