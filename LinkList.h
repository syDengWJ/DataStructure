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
extern Status ListInit(LinkList *L);	/*��ʼ��*/
extern Status ListEmpty(LinkList L);	/*�ж������Ƿ�Ϊ��*/
extern Status ClearList(LinkList L);	/*������������Ԫ��*/
extern Status ListInsert(LinkList *L, int i, ElemType e);	/*����*/
extern Status GetElem(LinkList L, int i,ElemType *e);	/*��ȡ��i��Ԫ��*/
extern int LocateElem(LinkList L, ElemType e);		/*��ȡԪ��e��λ��*/
extern Status ListDelete(LinkList L,int i,ElemType *e);		/*ɾ����i��Ԫ��*/
extern void ListTraverse(LinkList L);			/*��������*/
extern int ListLength(LinkList L);				/*����������*/
extern void CreateListHead(LinkList L,int n);	/*�������n��Ԫ�أ��ӱ�ͷ����*/
extern void CreateListTail(LinkList L,int n);	/*�������n��Ԫ�أ��ӱ�β����*/
#endif
