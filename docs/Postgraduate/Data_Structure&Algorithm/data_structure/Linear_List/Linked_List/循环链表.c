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

typedef LNode CLinkList; 


/*循环链表的初始化	|	InitList(L)*/
CLinkList* InitList(CLinkList *L)
{
	L = (CLinkList *)malloc(sizeof(CLinkList));
    if(!L)
    {
        printf("分配内存失败\n");
        return False;
    }
	L->data = 0;
	L->next = L;
    printf("循环链表初始化成功\n");
	return L;
}

/*空循环链表的判断	|	Is\_empty(L)	|	ClearList(L)*/
int Is_empty(CLinkList *L)
{
    if(L->next==L)
    {
    	printf("循环链表为空\n");
        return True;
    }
    else
    {
    	printf("循环链表不为空\n");
        return False;
    }
}


/*打印循环链表	|	PrintList(L)*/
int PrintList(CLinkList *L)
{
    int len=1;
    LNode *cur;
    cur = L->next;
    if(cur == L)
    {
        printf("循环链表打印失败,循环链表为空\n");
        return False;
    }
    else
    {
        while(cur != L)
        {
            printf("[%d]%d", len, cur->data);
            if(cur->next != L)
            {
                printf("->");
            }
            len ++;
            cur = cur->next;
        }
        printf("\n");
        printf("循环链表打印成功\n");
    	return True;
    }
}

/*插入结点(后插入)	|	Ins(L, index, val)*/
int Ins(CLinkList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    LNode *goal_Node;
    goal_Node = (LNode *)malloc(sizeof(LNode));
    goal_Node->data = val;
    goal_Node->next = L;
    LNode *cur;

    /*第一个结点情况*/
    if(L->next==L && index==0)    
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
    	while(cur!=L && count<index)
	    {
	        count ++;
	        cur = cur->next;
	    }
	    if(cur!=L && count==index)
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
int Del(CLinkList *L)
{
    int index;
    printf("输入索引值:");
    fflush(stdin); //清除键盘缓存
	scanf("%d", &index);
    
    LNode *cur, *pre;
    cur = L->next;
    pre = L;
    int count=1;
    
    while(cur!=L && count<index)
    {
        count ++;
        pre = cur;
        cur = cur->next;
    }
    if(cur!=L)
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
	CLinkList *L;
	L = InitList(L);
	
	int sign, exit=0;
	while(1)
	{
		int index, Item;
		printf("=======================\n");
		printf("1 - 循环链表的初始化\n");
		printf("2 - 空循环链表的判断\n");
		printf("3 - 打印循环链表\n");
		printf("4 - 插入结点(后插入)\n");
		printf("5 - 删除结点\n");
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
				L=InitList(L);break;
			case 2:
				Is_empty(L);break;
			case 3:
				PrintList(L);break;
			case 4:
				Ins(L);break;
			case 5:
				Del(L);break;
		}
		if(exit == 1)
		{break;}
	}
}