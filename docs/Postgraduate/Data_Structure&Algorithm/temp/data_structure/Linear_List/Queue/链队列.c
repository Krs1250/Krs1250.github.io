#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

typedef int DataType;
/*链节点*/
typedef struct QNode
{
    DataType data;
    struct QNode *next;
}QNode;
/*链队列*/
typedef struct
{
    QNode *front;
    QNode *rear; 
}LinkQueue;

/*队列初始化*/
LinkQueue* InitQueue(LinkQueue *Q)
{
    QNode *head;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    head = (QNode *)malloc(sizeof(QNode));
    Q->front = Q->rear = head;
    printf("队列初始化成功\n");
    return Q;
}

/*打印队列*/
int PrintQueue(LinkQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("打印队列失败，队列为空\n");
        return False;
    }
    else
    {
        QNode *cur;
        cur = Q->front->next;
        while(cur != NULL)
        {
            printf("%d", cur->data);
            if(cur->next != NULL)
            {
                printf("->");
            }
            cur = cur->next;
        }
        printf("\n");
        printf("打印队列成功\n");
        return True;
    }
}

/*取队头元素*/
DataType GetHead(LinkQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("取队头元素失败，链队列为空\n");
        return False;
    }
    else
    {
        printf("取队头元素成功，元素为%d\n", Q->front->next->data);
        return Q->front->next->data;
    }
}

/*入队*/
int EnQueue(LinkQueue *Q)
{
    int x;
    printf("输入数据：");
    fflush(stdin);
    scanf("%d", &x);

    QNode *temp;
    /*malloc问题*/
    temp = (QNode *)malloc(sizeof(QNode));
    temp->next = NULL;
    temp->data = x;

    Q->rear->next = temp;
    Q->rear = temp;
    
    printf("入队成功\n");
    return True;
}

/*出队*/
DataType DeQueue(LinkQueue *Q)
{
    if(Q->front == Q->rear)
    {
        printf("出队失败，队列为空\n");
        return False;
    }
    else
    {
        QNode *temp;
        int x;
        temp = Q->front->next;
        x = temp->data;
        Q->front->next = Q->front->next->next;
        if(Q->rear == temp)
        {
            Q->rear = Q->front;
        }
        printf("出队成功,出队元素为：%d\n", x);
        return x;
    }
}

void main()
{
    LinkQueue *Q;
    Q = InitQueue(Q);
    
    int sign,exit=0;
    while(1)
    {
        printf("======================\n");
        printf("1 - 队列初始化\n");
        printf("2 - 打印队列\n");
        printf("3 - 取队头元素\n");
        printf("4 - 入队\n");
        printf("5 - 出队\n");
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
                Q = InitQueue(Q);break;
            case 2:
                PrintQueue(Q);break;
            case 3:
                GetHead(Q);break;
            case 4:
                EnQueue(Q);break;
            case 5:
                DeQueue(Q);break;
        }
        if(exit == 1)
        {
            break;
        }
    }
}

