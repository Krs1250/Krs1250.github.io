#include <stdio.h>
#include <malloc.h>

/*True\False 的宏定义*/
#define True 1
#define False 0

typedef int DataType;

typedef struct LNode
{
    DataType data;
    struct LNode *next;
}LNode;

typedef LNode LinkList; 


/*单链表的初始化	|	InitList(L)*/
LinkList* InitList(LinkList *L)
{
	L = (LinkList *)malloc(sizeof(LinkList));
    if(!L)
    {
        printf("分配内存失败\n");
        return False;
    }
	L->data = 0;
	L->next = NULL;
    printf("单链表初始化成功\n");
	return L;
}

/*清除单链表的内容	|	ClearList(L)*/
int ClearList(LinkList *L)
{
    LNode *cur, *temp;
    temp = (LNode *)malloc(sizeof(LNode));
    cur = L;
    while(cur->next != NULL)
    {
        temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
    }
    printf("清空顺序表成功\n");
    return True;
}

/*求表长	|	ListLength(L)*/
int ListLength(LinkList *L)
{
    int len=0;
    LNode *cur;
    cur = L->next;
    while(cur != NULL)
    {
        len ++;
        cur = cur->next;
	}
    printf("表长为%d\n", len);
    return len;
}

/*打印单链表	|	PrintList(L)*/
int PrintList(LinkList *L)
{
    int len=1;
    LNode *cur;
    cur = L->next;
    if(cur == NULL)
    {
        printf("单链表打印失败,单链表为空\n");
        return False;
    }
    else
    {
        while(cur != NULL)
        {
            printf("[%d]%d", len, cur->data);
            if(cur->next != NULL)
            {
                printf("->");
            }
            len ++;
            cur = cur->next;
        }
        printf("\n");
        printf("单链表打印成功\n");
    	return True;
    }
}

/*定位(按值查找)	|	Loc(L, val)*/
int Loc(LinkList *L)
{
    int val;
    printf("输入插入查找值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d", &val);
    
    LNode *cur;
    cur = L->next;
    int count = 1;
    while(cur!=NULL && cur->data!=val)
    {
        count ++;
        cur = cur->next;
    }
    if(cur!=NULL)
    {
        printf("索引值为：%d\n", count);
        printf("查找值存在\n");
        return count;
    }
    else
    {
        printf("查找值不存在\n");
        return False;
    }
}

/*插入结点(后插入)	|	Ins(L, index, val)*/
int Ins(LinkList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    LNode *goal_Node;
    goal_Node = (LNode *)malloc(sizeof(LNode));
    goal_Node->data = val;
    goal_Node->next = NULL;
    LNode *cur;

    /*第一个结点情况*/
    if(L->next==NULL && index==0)    
    {
    	cur = L;
	    cur->next = goal_Node;
	    printf("插入结点成功\n");
	    return True;
	}
    /*非第一个结点情况*/
    else
    {
    	cur = L->next;
    	int count = 1;
    	while(cur!=NULL && count<index)
	    {
	        count ++;
	        cur = cur->next;
	    }
	    if(cur!=NULL && count==index)
	    {
	        goal_Node->next = cur->next;
	        cur->next = goal_Node;
	        printf("插入结点成功\n");
	        return True;
	    }
	    else
	    {
	        printf("插入结点失败\n"); 
	        return False;
	    } 
	}
}

/*删除结点	|	Del(L, index)*/
int Del(LinkList *L)
{
    int index;
    printf("输入索引值:");
    fflush(stdin); //清除键盘缓存
	scanf("%d", &index);
    
    LNode *cur, *pre;
    cur = L->next;
    pre = L;
    int count=1;
    
    while(cur!=NULL && count<index)
    {
        count ++;
        pre = cur;
        cur = cur->next;
    }
    if(cur!=NULL)
    {
        pre->next = pre->next->next;
        printf("删除结点成功\n");
        return True;
    }
    else
    {
        printf("删除结点失败\n");
        return False;
    }
}


void main()
{
	LinkList *L;
	L = InitList(L);
	
	int sign, exit=0;
	while(1)
	{
		int index, Item;
		printf("=======================\n");
		printf("1 - 清除单链表的内容\n");
		printf("2 - 求表长\n");
		printf("3 - 打印单链表\n");
		printf("4 - 定位(按值查找)\n");
		printf("5 - 插入结点(后插入)\n");
		printf("6 - 删除结点\n");
		printf("0 - 退出\n");
		printf("=======================\n");
		printf("输入指令:\n");
		fflush(stdin);	//清除键盘缓冲区
		scanf("%d", &sign);
		switch(sign)
		{
			case 0:
				exit = 1; break;
			case 1:
				ClearList(L);break;
			case 2:
				ListLength(L);break;
			case 3:
				PrintList(L);break;
			case 4:
				Loc(L);break;
			case 5:
				Ins(L);break;
			case 6:
				Del(L);break;
		}
		if(exit == 1)
		{break;}
	}
}