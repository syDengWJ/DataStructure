#include "stdio.h"
#include "SqList.h"

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

/**/
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else 
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListTraverse(SqList L)
{
	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
	int n=ListLength(*L);
	if (n==MAXSIZE || i<1 || i>n+1)
		return ERROR;
	if (i<=n)
	{
		int k;
		for (k=n;k>=i;k--)
			L->data[k]=L->data[k-1];
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	int n=ListLength(*L);
	if (n == 0 || i<1 || i>n)
		return ERROR;
	int k;
	*e=L->data[i-1];
	if (i<n)
	{
		for (k=i;k<n;k++)
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

Status GetElem(SqList L,int i,ElemType *e)
{
	int n=ListLength(L);
	if (n==0 || i<1 || i>n)
		return ERROR;
	else
		*e = L.data[i-1];
	return OK;
}

int LocateElem(SqList L,ElemType e)
{
	int n=ListLength(L);
	if (n==0)
		return ERROR;
	int i;
	for (i=0;i<n;i++)
	{
		if (e == L.data[i])
			return i+1;
	}
	return ERROR;
}

Status unionL(SqList *La,SqList Lb)
{
	int len_La=ListLength(*La);
	int len_Lb=ListLength(Lb);
	int i;
	ElemType e;
	for (i=1;i<=len_Lb;i++)
	{
		GetElem(Lb,i,&e);
		if (!LocateElem(*La,e))
			ListInsert(La,++len_La,e);
	}
	return OK;
}