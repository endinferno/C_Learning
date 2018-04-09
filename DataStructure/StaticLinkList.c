#include <stdio.h>

#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

void InitList(StaticLinkList space);
int Malloc_SSL(StaticLinkList space);
void ListInsert(StaticLinkList L, int i, ElemType e);
int ListLength(StaticLinkList L);
void Free_SSL(StaticLinkList space, int k);
void ListDelete(StaticLinkList L, int i);

void InitList(StaticLinkList space)
{
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = 0;
    }
    space[MAXSIZE - 1].cur = 0;
}

int Malloc_SSL(StaticLinkList space)
{
    int i = space[0].cur;

    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

void ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1)
    {
        printf("Error: Out of limit.\n");
        return;
    }
    j = Malloc_SSL(L);
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
    }
}

int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}

void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
    {
        printf("Error: Out of limit.\n");
        return;
    }
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
    {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
}
