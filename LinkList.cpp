#include "LinkList.h"

/*��ʼ��,ͷָ�����ռ䣬���洢����*/
Status ListInit(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!*L)
		return ERROR;
	(*L)->nxt = NULL;
	return OK;
}

/*�ж������Ƿ�Ϊ��*/
Status ListEmpty(LinkList L)
{
	if (L->nxt)
		return FALSE;
	else
		return TRUE;
}

/*�Ϳα����в�ͬ��������û�����ͷ���*/
Status ClearList(LinkList L)
{
	LinkList  p, q;
	p = L->nxt;
	while (p)
	{
		q = p->nxt;
		free(p);
		p = q;
	}
	L->nxt = NULL;
	return OK;
}

/*�ڵ�i��Ԫ��ǰ����Ԫ��e*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int k = ListLength(*L);
	if (i<1 || i>k + 1)
		return ERROR;
	LinkList p;
	int j = 1;
	p = *L;
	LinkList temp = (LinkList)(malloc(sizeof(Node)));
	temp->data = e;
	temp->nxt = NULL;
	while (p && j < i)
	{
		p = p->nxt;
		++j;
	}
	temp->nxt = p->nxt;
	p->nxt = temp;
	return OK;
}

/*�������n��Ԫ�أ�����n����ͷ����Ԫ��(����ͷ���)*/
void CreateListHead(LinkList L, int n)
{
	srand(time(0));
//	L = (LinkList)malloc(sizeof(Node));
//	L->nxt = NULL;
	int i = 0;
	while (i < n)
	{
		LinkList p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 101;
		p->nxt = L->nxt;
		L->nxt = p;
		++i;
	}
}

/*�������n��Ԫ�أ��ӱ�β����*/
void CreateListTail(LinkList L, int n)
{
	srand(time(0));
//	L = (LinkList)malloc(sizeof(Node));
//	L->nxt = NULL;
	LinkList q = L;
	int i = 0;
	while (i < n)
	{
		LinkList p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 101;
		p->nxt = NULL;
		q->nxt = p;
		q = p;
		++i;
	}
	q->nxt = NULL;
}
/*��ȡ��i��Ԫ��*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int k = ListLength(L);/*���iԽ�磬���󷵻�*/
	if (i<1 || i>k)
		return ERROR;

	LinkList p;
	p = L;
	int j = 0;
	while (p && j<i)
	{
		p = p->nxt;
		++j;
	}
	*e = p->data;
	return OK;
}

/*��ȡԪ��e��λ��*/
int LocateElem(LinkList L, ElemType e)
{
	LinkList p;
	p = L;
	int i = 0;
	while (p)
	{
		p = p->nxt;
		++i;
		if (p->data == e)
			return i;
	}
	return -1;
}

/*ɾ����i��Ԫ��*/
Status ListDelete(LinkList L, int i,ElemType *e)
{
	int k = ListLength(L);
	if (k==0 || i<1 || i>k)
		return ERROR;
	LinkList p,q=NULL;
	int j = 0;
	p = L;
	while (p && j<i)
	{
		q = p;
		p = p->nxt;
		++j;
	}
	*e = p->data;
	q->nxt = p->nxt;
	free(p);
	return OK;
}

/*��������*/
void ListTraverse(LinkList L)
{
	LinkList p;
	p = L->nxt;
	while (p)
	{
		printf("%d ", p->data);
		p = p->nxt;
	}
	printf("\n");
}

/*����������*/
int ListLength(LinkList L)
{
	int len = 0;
	LinkList p = L->nxt;
	while (p)
	{
		p = p->nxt;
		++len;
	}
	return len;
}