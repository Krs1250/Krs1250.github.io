#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

// 法1 用单链表存放串
typedef struct cnode
{
	char ch;
	struct cnode *next;
}cnode, LinkString;

// 法2 
#define ChunkSize=4 //定义块大小
typedef struct Chunk //定义块链结点结构
{
	char str[ChunkSize];
	struct CHUNK *next;
}Chunk;
typedef struct //定义块链存储结构
{
	Chunk *head, *tail; //链表头指针和尾脂针
	int strlen; //串的实际长度
}


void main()
{
	LinkString *head;
	
}
