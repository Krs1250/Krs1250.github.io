#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

#define Max_Degree_Size 10
typedef int DataType;
typedef struct TNode
{
	struct TNode prior;
	DataType data;
	struct TNode next[Max_Degree_Size];
	int degree;
}TNode;
typedef struct
{
	TNode *root;
	int level;
}Tree;

/*初始化树*/
Tree* Init_Tree(Tree *T)
{
	T = (Tree *)malloc(sizeof(T));
	TNode *root;
	root = (TNode *)malloc(sizeof(TNode));
	root->prior = NULL;
	root->degree = 0;
	
	T->root = root;
	T->level = 1;
	
	return T;
}

/*求树的树根*/
TNode* Get_Root(Tree *T)
{
	// 直接return结点，需要其数据可以在外面进行操作
	// ps：可能需要担心数据泄漏问题？
	return T->root;
}

/*创建一棵树*/
Tree* Create_Tree(Tree *T)
{
	
}

/*求结点x的双亲结点*/
TNode* Parent(Tree *T, TNode *x)
{
	
}

/*求树T中结点x的第i个孩子结点*/
TNode* Child(Tree *T, TNode *x, int i)
{
	
}

/*插入子树*/
int Insert_Child(Tree *Y, int i, Tree X)
{
	
}

/*删除子树*/
int Delet_Child(TNode *x, int i)
{
	
}

/*数的遍历*/
int Traverse_Tree(TNode *T)
{
	
}

/*清除树结构*/
int Clear(Tree *T)
{
	
}

int EmptyTree(Tree *T)
{
	
}

void main()
{
	Tree *T;
}