#ifndef SQLIST_H_
#define SQLIST_H_

#include "stdio.h"

#define MAXSIZE 20
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct List
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

/*Operations*/
extern Status InitList(SqList *L);
extern Status ListEmpty(SqList L);
extern Status ClearList(SqList *L);
extern int ListLength(SqList L);
extern Status ListTraverse(SqList L);
extern Status ListInsert(SqList *L,int i,ElemType e);
extern Status ListDelete(SqList *L,int i,ElemType *e);
extern ElemType GetElem(SqList L,int i,ElemType *e);
extern int LocateElem(SqList L,ElemType e);
extern Status unionL(SqList *La,SqList Lb);

#endif