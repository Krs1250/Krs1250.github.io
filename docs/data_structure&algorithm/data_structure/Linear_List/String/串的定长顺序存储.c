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
    printf("%d", s->length);
} 

/*串复制*/
SeqString* Strcpy(SeqString *s, SeqString *t)
{
    for(int i=0; i<s->length; i++)
    {
        t->ch[i] = s->ch[i];
    }
    return t;
}

/*串连接*/
SeqString* Strcat(SeqString *s, SeqString *t)
{
    if(s->length + 1);
}

/*求子串*/


/*串删除*/


void main()
{
    SeqString *s;
    s = InitStr(s);

    SeqString *t;
    t = InitStr(t);

}