/*
 * @Author: endinferno.DataStructure 
 * @Description: Single List
 * @Date: 2018-04-08 19:24:10 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-08 19:26:48
 */

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

void GetElem(LinkList L, int i, ElemType *e);
void ListInsert(LinkList *L, int i, ElemType e);
void ListDelete(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);

void GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        printf("Error: Out of limit.\n");
        return;
    }
    *e = p->data;
}

void ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j < i)
    {
        printf("Error: Out of limit.\n");
        return;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

void ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = i;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        printf("Error: Out of limit.\n");
        return;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
}

void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = 0;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (int i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = 0;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

