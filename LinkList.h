#pragma once
#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

/*the definition of link list node*/
typedef struct Node
{
	ElemType data;
	struct Node * nxt;
}ListNode;

typedef ListNode *LinkList;

/*Declaration of operations*/
extern Status ListInit(LinkList *L);	/*初始化*/
extern Status ListEmpty(LinkList L);	/*判断链表是否为空*/
extern Status ClearList(LinkList L);	/*清除链表的所有元素*/
extern Status ListInsert(LinkList *L, int i, ElemType e);	/*插入*/
extern Status GetElem(LinkList L, int i,ElemType *e);	/*获取第i个元素*/
extern int LocateElem(LinkList L, ElemType e);		/*获取元素e的位置*/
extern Status ListDelete(LinkList L,int i,ElemType *e);		/*删除第i个元素*/
extern void ListTraverse(LinkList L);			/*遍历链表*/
extern int ListLength(LinkList L);				/*返回链表长度*/
extern void CreateListHead(LinkList L,int n);	/*随机产生n个元素，从表头插入*/
extern void CreateListTail(LinkList L,int n);	/*随机产生n个元素，从表尾插入*/
#endif
