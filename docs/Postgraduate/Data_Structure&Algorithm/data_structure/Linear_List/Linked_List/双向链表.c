#include <stdio.h>
#include <malloc.h>

/*True\False 的宏定义*/
#define True 1
#define False 0

typedef int DataType;

typedef struct LNode
{
    struct LNode *prior;
    DataType data;
    struct LNode *next;
}LNode;

typedef LNode DLinkList; 


/*双向链表的初始化	|	InitList(L)*/
DLinkList* InitList(DLinkList *L)
{
	L = (DLinkList *)malloc(sizeof(DLinkList));
    if(!L)
    {
        printf("分配内存失败\n");
        return False;
    }
    L->prior= NULL;
	L->data = 0;
	L->next = NULL;
    printf("双向链表初始化成功\n");
	return L;
}

/*空双向链表的判断	|	Is\_empty(L)	|	ClearList(L)*/
int Is_empty(DLinkList *L)
{
    if(L->next==NULL && L->prior==NULL)
    {
    	printf("双向链表为空\n");
        return True;
    }
    else
    {
    	printf("双向链表不为空\n");
        return False;
    }
}

/*打印双向链表	|	PrintList(L)*/
int PrintList(DLinkList *L)
{
    int len;
    LNode *cur;
    cur = L;
    if(cur->next==NULL && cur->prior==NULL)
    {
        printf("双向链表打印失败,双向链表为空\n");
        return False;
    }
    else
    {
    	/*prior部分*/
    	cur = L;
    	len = 0;
        while(cur->prior != NULL)
        {
            len ++;
            cur = cur->prior;
        }
        while(len>0)
        {
            printf("%d[%d]", cur->data, len);
            if(len>1)
            {
                printf("<-");
            }
            cur = cur->next;
            len --;
        }
    	printf("[-]");
		
    	/*next部分*/
    	cur = L->next;
    	len = 1;
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
        printf("双向链表打印成功\n");
    	return True;
    }
}

/*插入结点(前插入)	|	Ins_f(L, index, val)*/
int Ins_f(DLinkList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    LNode *goal_Node;
    goal_Node = (LNode *)malloc(sizeof(LNode));
    goal_Node->prior= NULL;
    goal_Node->data = val;
    goal_Node->next = NULL;
    LNode *cur;

    /*第一个结点情况*/
    if(L->prior==NULL && index==0)    
    {
    	cur = L;
	    goal_Node->next = cur;
        goal_Node->prior = cur->prior;
        if(cur->prior!=NULL)
        {
        	cur->prior->next = goal_Node;
		}
        cur->prior = goal_Node;
	    printf("插入prior结点成功\n");
	    return True;
	}
    /*非第一个结点情况*/
    else
    {
    	cur = L->prior;
    	int count = 1;
    	while(cur!=NULL && count<index)
	    {
	        count ++;
	        cur = cur->prior;
	    }
	    if(cur!=NULL && count==index)
	    {
	    	goal_Node->next = cur;
	        goal_Node->prior = cur->prior;
	        if(cur->prior!=NULL)
	        {
	        	cur->prior->next = goal_Node;	
			}
	        cur->prior = goal_Node;
	        printf("插入prior结点成功\n");
	        return True;
	    }
	    else
	    {
	        printf("插入prior结点失败\n"); 
	        return False;
	    } 
	}
}

/*插入结点(后插入)	|	Ins_b(L, index, val)*/
int Ins_b(DLinkList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    LNode *goal_Node;
    goal_Node = (LNode *)malloc(sizeof(LNode));
    goal_Node->prior= NULL;
    goal_Node->data = val;
    goal_Node->next = NULL;
    LNode *cur;

    /*第一个结点情况*/
    if(L->next==NULL && index==0)    
    {
    	cur = L;
	    goal_Node->prior = cur;
        goal_Node->next = cur->next;
        if(cur->next!=NULL)
        {
       		cur->next->prior = goal_Node;
		}
        cur->next = goal_Node;
	    printf("插入next结点成功\n");
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
	    if(cur!=L && count==index)
	    {
	    	goal_Node->prior = cur;
	        goal_Node->next = cur->next;
	        if(cur->next!=NULL)
        	{
	        	cur->next->prior = goal_Node;
	    	}
	        cur->next = goal_Node;
	        printf("插入next结点成功\n");
	        return True;
	    }
	    else
	    {
	        printf("插入next结点失败\n"); 
	        return False;
	    } 
	}
}
/*删除结点(前删除)*/
int Del_f(DLinkList *L)
{
    int index;
    printf("输入索引值:");
    fflush(stdin); //清除键盘缓存
	scanf("%d", &index);
    
    LNode *cur, *pre;
    cur = L->prior;
    pre = L;
    int count=1;
    
    while(cur!=NULL && count<index)
    {
        count ++;
        pre = cur;
        cur = cur->prior;
    }
    if(cur!=NULL)
    {
    	if(cur->prior!=NULL)
    	{
    		pre->prior->prior->next = pre;
		}
        pre->prior = pre->prior->prior;
        printf("删除结点成功\n");
        return True;
    }
    else
    {
        printf("删除结点失败\n");
        return False;
    }
}


/*删除结点(后删除)	|	Del(L, index)*/
int Del_b(DLinkList *L)
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
    	if(cur->next!=NULL)
    	{
    		pre->next->next->prior = pre;
		}
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
	DLinkList *L;
	L = InitList(L);
	
	int sign, exit=0;
	while(1)
	{
		int index, Item;
		printf("=======================\n");
		printf("1 - 双向链表的初始化\n");
		printf("2 - 空双向链表的判断\n");
		printf("3 - 打印双向链表\n");
		printf("41 - 插入结点(前插入)\n");
		printf("42 - 插入结点(后插入)\n");
		printf("51 - 删除结点(前删除)\n");
		printf("52 - 删除结点(后删除)\n");
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
			case 41:
				Ins_f(L);break;
			case 42:
				Ins_b(L);break;
			case 51:
				Del_f(L);break;
			case 52:
				Del_b(L);break;
		}
		if(exit == 1)
		{break;}
	}
}