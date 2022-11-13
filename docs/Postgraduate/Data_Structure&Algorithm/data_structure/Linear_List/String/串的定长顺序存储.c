#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

#define MaxStrSize 256

typedef struct
{
    char ch[MaxStrSize];
    int length;
}SeqString;

/*串初始化*/
SeqString* InitStr(SeqString *s)
{
    s = (SeqString *)malloc(sizeof(SeqString));
    s->length = 0;

    printf("输入字符串：");
	fflush(stdin);
    scanf("%s", s->ch);
    
    while(s->ch[s->length] != '\0')
    {
        s->length ++;
    }
    printf("串初始化成功\n");
    return s;
}

/*求串长*/
int Strlen(SeqString *s)
{
    printf("%d\n", s->length);
	return s->length;
} 

/*串复制*/
SeqString* Strcpy(SeqString *s, SeqString *t)
{
    for(int i=0; i<s->length; i++)
    {
        t->ch[i] = s->ch[i];
    }
	printf("串复制成功\n");
    return t;
}

/*串连接*/
SeqString* Strcat(SeqString *s, SeqString *t)
{
    if(s->length + t->length > MaxStrSize)
	{
		for(int i=0; i<MaxStrSize-s->length; i++)
		{
			s->ch[i+s->length] = t->ch[i];
		}
		s->length = MaxStrSize;
		printf("串连接失败，超过串定义的最大长度\n");
		return False;
	}
	else
	{
		for(int i=0; i<t->length;i++)
		{
			s->ch[i+s->length] = t->ch[i];
		}
		s->length += t->length;
		printf("串连接成功\n");
		return s;
	}
	
}

/*求子串*/
SeqString* Substr(SeqString *s)
{
	int pos, len;
	// pos(position) 串s中第pos个字符
	// len(length) 子串长度len
	// sub 子串
	SeqString *sub;
	sub = (SeqString *)malloc(sizeof(SeqString));
	sub->length = 0;

	printf("请输入pos&len:");
	fflush(stdin);
	scanf("%d %d", &pos, &len);
	
	// 判断pos和len和合法性
	if((pos<1 || pos>=s->length)\
	|| len+pos>s->length+1)
	{
		printf("求子串失败，输入pos&len错误\n");
		return False;
	}
	
	for(int i=0; i<len; i++)
	{
		sub->ch[i] = s->ch[i+pos-1];
		printf("%c- %c", sub->ch[i], s->ch[i+pos-1]);
		sub->length+=1;	
	}
	printf("求子串成功\n");
	return sub;
}

/*串删除*/
SeqString* StrDelete(SeqString *s)
{
	int pos, len;
	// pos(position) 串s中第pos个字符
	// len(length) pos位置开始往后len个字符
	
	printf("请输入pos&len:");
	fflush(stdin);
	scanf("%d %d", &pos, &len);
	
	// 判断pos和len和合法性
	if((pos<1 || pos>=s->length)\
	|| len+pos>s->length+1)
	{
		printf("串删除失败，输入pos&len错误\n");
		return False;
	}
	
	for(int i=pos+len-1; i<s->length; i++)
	{
		// 感觉自己很难理解这种数字与数字距离之间的关系。
		s->ch[i-len] = s->ch[i];
	}
	s->length = s->length-len;
	printf("串删除成功\n");
	return s;
}

void main()
{
	// 字符串 s	
    SeqString *s;
    s = InitStr(s);
	// 字符串 t
    SeqString *t;
    t = InitStr(t);
	// result
	SeqString *result;
	result = InitStr(result);

	while(1)
	{
		int sign=0,exit=0;
		printf("=========================\n");
		printf("字符串s = %s\n", s->ch);
		printf("字符串t = %s\n", t->ch);
		printf("字符串result = %s\n", result->ch);
		printf("1 - 串初始化(s&t)\n");
		printf("2 - 求串长(s)\n");
		printf("3 - 串复制(s->t)\n");
		printf("4 - 串连接(s-t)\n");
		printf("5 - 求子串(s)\n");
		printf("6 - 串删除(s)\n");
		printf("=========================\n");
		printf("输入指令:");
		scanf("%d", &sign);
		switch(sign)
		{
			case 0:
				exit = 1;break;
			case 1:
				result = InitStr(s);t = InitStr(t);break;
			case 2:
				Strlen(s);break;
			case 3:
				result = Strcpy(s, t);break;
			case 4:
				result = Strcat(s, t);break;
			case 5:
				result = Substr(s);break;
			case 6:
				result = StrDelete(s);break;
		}
		if(exit == 1){break;}		
	}
}
