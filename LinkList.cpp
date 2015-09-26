#include "LinkList.h"

/*初始化,头指针分配空间，不存储数据*/
Status ListInit(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!*L)
		return ERROR;
	(*L)->nxt = NULL;
	return OK;
}

/*判断链表是否为空*/
Status ListEmpty(LinkList L)
{
	if (L->nxt)
		return FALSE;
	else
		return TRUE;
}

/*和课本略有不同，我这里没有清除头结点*/
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

/*在第i个元素前插入元素e*/
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

/*随机产生n个元素，创建n个带头结点的元素(除了头结点)*/
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

/*随机产生n个元素，从表尾插入*/
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
/*获取第i个元素*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int k = ListLength(L);/*如果i越界，错误返回*/
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

/*获取元素e的位置*/
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

/*删除第i个元素*/
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

/*遍历链表*/
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

/*返回链表长度*/
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