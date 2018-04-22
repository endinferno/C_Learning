/*
 * @Author: endinferno.DataStructure 
 * @Description: Linear List
 * @Date: 2018-04-08 18:43:42 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-12 16:57:26
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define OVERFLOW 1
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    size_t length;
} SqList;

void InitList(SqList *L);
size_t LengthList(SqList L);
bool IsListEmpty(SqList L);
void ClearList(SqList *L);
void CreateListFromArray(SqList *L, int *num, int len);
void TraverseList(SqList L);
ElemType GetElemList(SqList L, size_t order);
size_t LocateElemList(SqList L, ElemType elem);
void InsertElemList(SqList *L, size_t order, ElemType elem);
ElemType ModifyElemList(SqList *L, size_t order, ElemType elem);
ElemType DeleteElemList(SqList *L, size_t order);
void DestroyList(SqList *L);
SqList CopySqList(SqList L);

void InitList(SqList *L)
{
    L->length = 0;
    printf("Init Success.\n");
}
size_t LengthList(SqList L)
{
    return L.length;
}
bool IsListEmpty(SqList L)
{
    return 0 == LengthList(L);
}
void ClearList(SqList *L)
{
    L->length = 0;
}
void CreateListFromArray(SqList *L, int *num, int len)
{
    if (len > MAXSIZE)
    {
        fprintf(stderr, "Error: Out of Limit.\n");
        exit(OVERFLOW);
    }
    L->length = len;
    for (int i = 0; i < len; i++)
    {
        L->data[i] = num[i];
    }
}
void TraverseList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}
ElemType GetElemList(SqList L, size_t order)
{
    if (order > L.length)
    {
        printf("Error: Out of Limit.\n");
        exit(OVERFLOW);
    }
    return L.data[order - 1];
}
size_t LocateElemList(SqList L, ElemType elem)
{
    for (int i = 0; i < L.length; i++)
    {
        if (elem == L.data[i])
            return i + 1;
    }
    return 0;
}
void InsertElemList(SqList *L, size_t order, ElemType elem)
{
    if (NULL == L)
    {
        fprintf(stderr, "Error: Failed to Insert Elem to NULL.\n");
        exit(OVERFLOW);
    }
    if (order < 0 || order > L->length || L->length > MAXSIZE)
    {
        fprintf(stderr, "Error: Out of Limit.\n");
        return;
    }
    for (size_t i = L->length; i > order; i--)
        L->data[i] = L->data[i - 1];
    L->data[order] = elem;
    L->length++;
}
ElemType ModifyElemList(SqList *L, size_t order, ElemType elem)
{
    if (order < 1 || order > L->length)
    {
        fprintf(stderr, "Error: Out of Limit.\n");
        exit(OVERFLOW);
    }
    ElemType value = L->data[order - 1];
    L->data[order - 1] = elem;
    return value;
}
ElemType DeleteElemList(SqList *L, size_t order)
{
    if (order > L->length || order < 1)
    {
        fprintf(stderr, "Error: Out of Limit\n");
        exit(OVERFLOW);
    }
    ElemType value = L->data[order - 1];
    for (size_t i = order; i < L->length; i++)
        L->data[i - 1] = L->data[i];
    L->length--;
    return value;
}
void DestroyList(SqList *L)
{
    L->length = 0;
}
SqList CopySqList(SqList L)
{
    SqList P = L;
    return P;
}