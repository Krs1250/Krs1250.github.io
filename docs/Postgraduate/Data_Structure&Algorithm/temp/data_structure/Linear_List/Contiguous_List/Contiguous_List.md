[TOC]

# 顺序表_SeqList(SequentList)

## 结点+	LNode(ListNode)

```C
/*True\False 的宏定义*/
#define True 1
#define False 0

/*通过宏来控制线性表的容纳数据大小*/
#define maxsize 1024

typedef int DataType;

typedef struct LNode
{a
    DataType elem[maxsize];
    int length;	//统计线性表长度保存在结构体中，方便需要的时候取得
}LNode SeqList;
```

## 1、顺序表的初始化_InitList(L)

```C
SeqList* InitList(SeqList *L)
{
    L = (SeqList *)malloc(sizeof(SeqList));
    if(!L)
    {
        printf("分配内存失败\n");
        return False;
    }
    L->length = 0;
    return L;
}
```

## 2、清除顺序表的内容_ClearList(L)

```C
int ClearList(SeqList *L)
{
    L->length = 0;
    printf("清空顺序表成功\n");
    return True;
}
```

## 3、打印顺序表_PrintList(L)

```C
int PrintList(SeqList *L)
{
    if(L->length != 0)
    {
		for(int i=0; i<(L->length); i++)
    	{
			printf("[%d]", L->elem[i]);
    	}
    	printf("\n");
    	printf("顺序表打印成功\n");
    	return True;
    }
    else
    {
        printf("顺序表打印失败,顺序表为空\n");
        return False;
    }
}
```

## 4、定位(按值查找)_Loc(L, val)

```C
int Loc(SeqList *L)
{
    int val;
    printf("输入插入查找值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d", &val);
    
    for(int i=0; i<L->length; i++)
    {
        if(L->elem[i] == val)
        {
            printf("%d\n", i);
            printf("查找值存在\n");
            return True;
        }
    }
    printf("查找值不存在\n");
    return False;
}
```

## 5、插入数据_Ins(L, index, val)

```C
int Ins(SeqList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    /*判断index是否合理*/
    if(index<0 || index>L->length)
    {
     	printf("插入数据失败\n"); 
     	return False;
    }
    else
    {
        for(int i=L->length; i>index; i--)
        {
            L->elem[i] = L->elem[i-1];
        }
        L->elem[index] = val;
        L->length++;
        printf("插入数据成功\n");
        return True;
    }
}
```

## 6、删除数据_Del(L, index)

```C
int Del(SeqList *L)
{
	int index;
    printf("输入索引值:");
    fflush(stdin); //清除键盘缓存
	scanf("%d", &index);
    
    /*判断index是否合理*/
    if(index<0 || index>L->length)
    {
     	printf("删除数据失败\n");
     	return False;
    }
    else
    {
        for(int i=index; i<L->length; i++)
        {
            L->elem[i] = L->elem[i+1];
        }
        L->length--;
        printf("删除数据成功\n");
        return True;
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

/*通过宏来控制线性表的容纳数据大小*/
#define maxsize 1024

typedef int DataType;

typedef struct LNode
{
    DataType elem[maxsize];
    int length;	//统计线性表长度保存在结构体中，方便需要的时候取得
}LNode;

typedef LNode SeqList;

/*顺序表的初始化	|	InitList(L)*/
SeqList* InitList(SeqList *L)
{
    L = (SeqList *)malloc(sizeof(SeqList));
    if(!L)
    {
        printf("分配内存失败\n");
        return False;
    }
    L->length = 0;
    printf("顺序表初始化成功\n");
    return L;
}

/*清除顺序表的内容	|	ClearList(L)*/
int ClearList(SeqList *L)
{
    L->length = 0;
    printf("清空顺序表成功\n");
    return True;
}

/*打印顺序表	|	PrintList(L)*/
int PrintList(SeqList *L)
{
    if(L->length != 0)
    {
		for(int i=0; i<(L->length); i++)
    	{
			printf("[%d]", L->elem[i]);
    	}
    	printf("\n");
    	printf("顺序表打印成功\n");
    	return True;
    }
    else
    {
        printf("顺序表打印失败,顺序表为空\n");
        return False;
    }
}

/*定位(按值查找)	|	Loc(L, val)*/
int Loc(SeqList *L)
{
    int val;
    printf("输入插入查找值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d", &val);
    
    for(int i=0; i<L->length; i++)
    {
        if(L->elem[i] == val)
        {
            printf("%d\n", i);
            printf("查找值存在");
            return True;
        }
    }
    printf("查找值不存在\n");
    return False;
}

/*插入数据	|	Ins(L, index, val)*/
int Ins(SeqList *L)
{
    int index,val;
    printf("输入索引值&插入值:");
    fflush(stdin); //清除键盘缓存
    scanf("%d %d", &index, &val);
    
    /*判断index是否合理*/
    if(index<0 || index>L->length)
    {
     	printf("插入数据失败\n"); 
     	return False;
    }
    else
    {
        for(int i=L->length; i>index; i--)
        {
            L->elem[i] = L->elem[i-1];
        }
        L->elem[index] = val;
        L->length++;
        printf("插入数据成功\n");
        return True;
    }
}

/*删除数据	|	Del(L, index)*/
int Del(SeqList *L)
{
	int index;
    printf("输入索引值:");
    fflush(stdin); //清除键盘缓存
	scanf("%d", &index);
    
    /*判断index是否合理*/
    if(index<0 || index>L->length)
    {
     	printf("删除数据失败\n");
     	return False;
    }
    else
    {
        for(int i=index; i<L->length; i++)
        {
            L->elem[i] = L->elem[i+1];
        }
        L->length--;
        printf("删除数据成功\n");
        return True;
    }
}

void main()
{
	SeqList *L;
	L = InitList(L);
	int sign = -1, exit=0;
	while(1)
	{
		printf("\
====================\n\
1 - 清除线性表内容\n\
2 - 打印线性表内容\n\
3 - 定位（按值查找）\n\
4 - 插入数据\n\
5 - 删除数据\n\
0 - 退出\n\
====================\n");
		fflush(stdin);
		scanf("%d", &sign);
		switch(sign)
		{
			case(0):
				exit=1; break;
			case(1):
				ClearList(L); break;
			case(2):
				PrintList(L); break;
			case(3):
				Loc(L);	break;
			case(4):
				Ins(L);	break;
			case(5):
				Del(L); break;
		}
		if(exit == 1)
			break;
	}
}
```

