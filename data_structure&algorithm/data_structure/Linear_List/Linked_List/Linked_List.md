[TOC]

# 单链表_LinkList(LinkedList)

## 构造单链表

```C
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
```

## 1、单链表的初始化_InitList(L)

```C
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
```



## 2、清除单链表的内容_ClearList(L)

```C
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
```



## 3、求表长_ListLength(L)
```C
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
```



## 4、打印单链表_PrintList(L)

```C
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
```



## 5、定位-按值查找_Loc(L, val)
```C
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
```



## 6、插入结点-后插入_Ins(L, index, val)

```C
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
```



## 7、删除结点_Del(L, index)

```C
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
```



## 完整的例子

```C
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
```



# 循环链表_CLinkList(CircularLinkedList)

## 构造循环链表

```C
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
```

## 1、循环链表的初始化_InitList(L)

```C
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
```

## 2、空循环链表的判断_Is\_empty(L)

```C
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
```

## 3、打印循环链表_PrintList(L)

```C
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
```

## 4、插入结点-后插入_Ins(L, index, val)

```C
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
```



## 5、删除结点_Del(L, index)

```C
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
```



## 完整的例子

```C
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
		printf("1 - 空循环链表的判断\n");
		printf("2 - 打印循环链表\n");
		printf("3 - 插入结点(后插入)\n");
		printf("4 - 删除结点\n");
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
				Is_empty(L);break;
			case 2:
				PrintList(L);break;
			case 3:
				Ins(L);break;
			case 4:
				Del(L);break;
		}
		if(exit == 1)
		{break;}
	}
}
```



# 双向链表_DLinkList(DoubleLinkedList)

## 构造双向链表

```C
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
```

## 1、双向链表的初始化_InitList(L)

```C
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
```



## 2、空双向链表的判断_Is_empty(L)

```C
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
```



## 3、打印双向链表_PrintList(L)

```C
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
    	cur = L->prior;
    	len = 1;
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
```



## 41、插入结点-前插入_Ins_f(L, index, val)

```c
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
```



## 42、插入结点-后插入_Ins_b(L, index, val)

```C
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
```

## 5、删除结点-前删除_Del_f(L, index)

```C
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
```



## 6、删除结点-后删除_Del_f(L, index)

```C
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
```



## 完整的例子

```C
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
```

# 双向循环链表_DCLinkList(DoubleCircularLinkedList)

## 构造双向循环链表

```C
/*True\False 的宏定义*/
#define True 1
#define False 0

typedef int DataType;

typedef struct LNode
{
    int *prior;
    DataType data;
    int *next;
}LNode;

typedef LNode DCLinkList; 
```

## 1、双向循环链表的初始化_InitList(L)



## 2、空双向循环链表的判断_Is_empty(L)



## 3、打印双向循环链表_PrintList(L)



## 4、插入结点_Ins(L, index, val)



## 5、删除结点_Del(L, index)



## 完整的例子





# 静态链表_SLinkList(StaticLinkedList)

## 构造静态链表

```C
/*True\False 的宏定义*/
#define True 1
#define False 0

/*通过宏来控制线性表的容纳数据大小*/
#define MAXSIZE 1000

typedef int DataType;

typedef struct LNode
{
    DataType data;
    int *next;
}LNode;

typedef LNode SLinkList[MAXSIZE]; 
```

## 1、静态链表的初始化_InitList(L)



## 2、空静态链表的判断_Is_empty(L)



## 3、打印静态链表_PrintList(L)



## 4、插入结点_Ins(L, index, val)



## 5、删除结点_Del(L, index)



## 完整的例子
