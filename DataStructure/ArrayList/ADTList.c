/*
 * @Author: endinferno.DataStructure 
 * @Description: Linear List
 * @Date: 2018-04-08 18:43:42 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-12 00:06:26
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;
typedef size_t Location;

void InitList(SqList *L);
bool ListEmpty(SqList L);
void ClearList(SqList *L);
void GetElem(SqList L, Location i, ElemType *e);
Location LocateElem(SqList L, ElemType e);
void ListInsert(SqList *L, Location i, ElemType e);
void ListDelete(SqList *L, Location i, ElemType *e);
size_t ListLength(SqList L);

void InitList(SqList *L)
{
    L->length = 0;
}

bool ListEmpty(SqList L)
{
    return L.length == 0;
}

void ClearList(SqList *L)
{
    L->length = 0;
}

void GetElem(SqList L, Location i, ElemType *e)
{
    if (i > L.length || i < 1)
    {
        fprintf(stderr, "Error: Out of limit.\n");
        return;
    }
    *e = L.data[i - 1];
}

Location LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (e == L.data[i])
        {
            return i;
        }
    }
    return 0;
}

void ListInsert(SqList *L, Location i, ElemType e)
{
    if (i > L->length || i < 1)
    {
        fprintf(stderr, "Error: Out of limit.\n");
        return;
    }
    for (int u = L->length; u >= i; u--)
    {
        L->data[u] = L->data[u - 1];
    }
    L->data[i - 1] = e;
    L->length++;
}

void ListDelete(SqList *L, Location i, ElemType *e)
{
    if (i > L->length || i < 1)
    {
        fprintf(stderr, "Error: Out of limit.\n");
        return;
    }
    *e = L->data[i - 1];
    for (int u = i; u < L->length; u++)
    {
        L->data[u - 1] = L->data[u];
    }
}

size_t ListLength(SqList L)
{
    return L.length;
}