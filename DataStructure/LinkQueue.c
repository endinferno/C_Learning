/*
 * @Author: endinferno.DataStructure 
 * @Description: Link Queue
 * @Date: 2018-04-11 18:09:09 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-11 18:16:02
 */

#include <stdio.h>
#include <stdbool.h>

#define OVERFLOW 1

typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

bool EnQueue(LinkQueue *Q, QElemType e);
bool DeQueue(LinkQueue *Q, QElemType *e);

bool EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

bool DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
        return false;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;

    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}
