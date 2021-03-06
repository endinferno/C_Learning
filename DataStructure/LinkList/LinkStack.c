/*
 * @Author: endinferno.DataStructure 
 * @Description: LinkStack
 * @Date: 2018-04-09 22:31:37 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-12 00:08:18
 */

#include <stdio.h>
#include <stdbool.h>

typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

bool Push(LinkStack *S, SElemType e);
bool Pop(LinkStack *S, SElemType *e);

bool Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!s)
    {
        fprintf(stderr, "Error: Failed to Malloc Memory.\n");
        exit(1);
    }
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return true;
}

bool Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*S))
        return false;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return true;
}
