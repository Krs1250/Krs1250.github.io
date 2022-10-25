#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

typedef struct
{
	char *ch;// char指向串起始地址
	int length;// 串的实际长度
}Hstring;

/*串初始化*/
Hstring* InitStr(Hstring *H)
{
	H = (Hstring *)malloc(sizeof(Hstring *));
	if(!H){printf("初始化失败,内存分配错误!\n");return False;}
	// len 字符串长度
	int len;
	printf("输入字符串长度:");
	fflush(stdin);
	scanf("%d", &len);
	H->ch = (char *)malloc(len);
	if(!H->ch){printf("初始化失败,内存分配错误!\n");return False;}
	// H->ch 字符串内容
	printf("输入字符串内容:");
	fflush(stdin);
	scanf("%s", H->ch);
	
	printf("串初始化成功\n");
	return True;
}

/*串连接*/
Hstring* Strcat(Hstring *s, Hstring *t)
{
	Hstring *new;
	new = (Hstring *)malloc(sizeof(Hstring));
	if(!new){printf("串连接失败，内存分配错误!");return False;}
	new->length = s->length + t->length;
	new->ch = (char *)malloc(new->length);
	if(!new->ch){printf("串连接失败，内存分配错误!");}
	
	for(int i=0; i<s->length; i++)
	{
		new->ch[i] = s->ch[i];
	}
	for(int i=0; i<t->length; i++)
	{
		new->ch[s->length+i] = t->ch[i];
	}
	printf("串连接成功\n");
	return new;
}

/*串插入*/
Hstring* StrInsert(Hstring *s, Hstring *t)
{
	// pos 定位位置
	int pos;
	printf("输入pos:");
	scanf("%d", &pos);
	if(pos<1 || pos>s->length)
	{
		printf("串插入错误,pos位置不正确\n");
		return False;
	}
	// new 新字符串
	Hstring *new;
	new = (Hstring *)malloc(sizeof(Hstring));
	if(!new){printf("串连接失败，内存分配错误!");return False;}
	new->length = s->length + t->length;
	new->ch = (char *)malloc(new->length);
	if(!new->ch){printf("串连接失败，内存分配错误!");}
	
	// 字符串s pos前半段
	for(int i=0; i<pos; i++)
	{
		new->ch[i] = s->ch[i];
	}
	// 字符串t 
	for(int i=0; i<t->length; i++)
	{
		new->ch[pos+i] = t->ch[i];
	}
	// 字符串s pos后半段
	for(int i=0; i<s->length-pos; i++)
	{
		new->ch[pos+s->length+i] = s->ch[pos+i];
	}
	printf("串插入成功\n");
	return new;
}

/*串删除*/
int StrDelete(Hstring *s)
{
	char *p;
	int pos,len;
	printf("输入pos&len");
	scanf("%d %d", &pos, &len);
	if(pos<1 || pos>s->length \
	|| len > s->length-pos+1)
	{
		printf("串删除失败，pos&len不正确\n");
		return False;
	}
	
	// p指向定位的位置
	p = s->ch + pos - 1;
	for(int i=0; i<len; i++)
	{
		*(p + i) = *(p + len + i);
	}
	s->length -= len;
	printf("串删除成功\n");
	return True;
}


void main()
{
	
}