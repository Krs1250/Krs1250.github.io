# Linear_List 线性表
*特征：*  
*- 有且只有一个"第一元素"*  
*- 有且只有一个"最后元素"*  
*- 除第一元素之外，其他元素都有唯一的直接前趋*  
*- 除最后元素之外，其他元素都有唯一的直接后继*  

## 线性表基本操作

- $InitList(L)$

- $ClearList(L)$

- $ListLength(L)$

- $Ins(L, index, val)$

- $Del(L, index)$

- $GetNext(L, val, p)$

- $GetNode(L, index)$

- $Loc(L, val)$

- $GetPrior(L, val, p)$

  <hr/>

- $PrintList(L)$

- $Is\_empty(L)$

## [顺序表](./Linear_List/Contiguous_List/Contiguous_List.md)
*特征：线性表的顺序存储方式，是指利用一段连续的内存地址来存储线性表的数据元素。*

## [链表_LinkList(LinkedList)](./Linear_List/Linked_List/Linked_List.md)
*特征：线性表的链式存储方式，是指用一组任意的存储单元来存储线性表的结点。*  
*优点：能够方便地增加和删除线性表中的元素*  
*缺点：使随机存储、获取直接前趋和直接后继变得较为复杂*

### 单链表_LinkList(LinkedList)

### 循环链表_CLinkList(CircularLinkedList)

### 双向链表_DLinkList(DoubleLinkedList)

### 双向循环链表_DCLinkList(DoubleCircularLinkedList)

### 静态链表_SLinkList(StaticLinkedList)

## 线性表的应用

# 栈和队列

栈和队列是<u>操作受限的线性表</u>，也可称为<u>限定性的线性表结构</u>。  

## [栈_Stack](./Linear_List/Stack/Stack.md)
*特征：后进先出*  

### 顺序栈_SeqStack(SequentStack)

### 链栈_LinkStack(LinkedStack)

### 栈的应用

## [队列_Queue](./Linear_List/Queue/Queue.md)
*特征：先进先出*  

### 链队列_LinkQueue(LinkedQueue)

### 顺序队列_SeqQueue(SequentQueue)

### 队列的应用

# 串_String
**字符串**(简称串)是一种<u>特殊的线性表</u>，它的每个节点仅由一个字符组成。

