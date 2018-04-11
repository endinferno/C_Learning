/*
 * @Author: endinferno.DataStructure 
 * @Description: SqQueue(TWO POINTERS)(Consider False Spillover)
 * @Date: 2018-04-11 17:01:10 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-11 18:08:24
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

bool InitQueue(SqQueue *Q);
//Can't be done
//same reason.
//SEE DataStructure/SqQueueWithOnePointer.c
bool DestroyQueue(SqQueue *Q);
bool ClearQueue(SqQueue *Q);
bool QueueEmpty(SqQueue Q);
int Queuelength(SqQueue Q);
bool EnQueue(SqQueue *Q, QElemType e);
bool DeQueue(SqQueue *Q, QElemType *e);

bool InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

bool ClearQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

bool QueueEmpty(SqQueue Q)
{
}

int Queuelength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

bool EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return false;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) & MAXSIZE;
    return true;
}