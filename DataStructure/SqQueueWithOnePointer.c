/*
 * @Author: endinferno.DataStructure 
 * @Description: SqQueue(ONE POINTER)
 * @Date: 2018-04-11 16:27:52 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-11 16:58:41
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int rear;
} SqQueue;

bool InitQueue(SqQueue *Q);
//Can't be done.
//Memory malloc in the beginnning of the program
//Memory is in stack.
//Memory will be freed when the program is over.
bool DestroyQueue(SqQueue *Q);
bool ClearQueue(SqQueue *Q);
bool QueueEmpty(SqQueue Q);
bool GetHead(SqQueue Q, QElemType *e);
bool EnQueue(SqQueue *Q, QElemType e);
bool DeQueue(SqQueue *Q, QElemType *e);
int QueueLength(SqQueue Q);

bool InitQueue(SqQueue *Q)
{
    Q->rear = 0;
    return true;
}

bool DestroyQueue(SqQueue *Q) {}

bool ClearQueue(SqQueue *Q)
{
    Q->rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    return 0 == Q.rear;
}

bool GetHead(SqQueue Q, QElemType *e)
{
    if (Q.rear == 0)
        return false;
    *e = Q.data[0];
    return true;
}

bool EnQueue(SqQueue *Q, QElemType e)
{
    if (Q->rear >= MAXSIZE)
        return false;
    Q->data[Q->rear] = e;
    Q->rear++;
    return true;
}

bool DeQueue(SqQueue *Q, QElemType *e)
{
    if (0 == Q->rear)
    {
        *e = 0;
        return false;
    }
    *e = Q->data[0];
    for (int i = 1; i < Q->rear; i++)
        Q->data[i - 1] = Q->data[i];
    return true;
}

int QueueLength(SqQueue Q)
{
    return Q.rear;
}