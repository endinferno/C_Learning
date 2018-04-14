/*
 * @Author: endinferno.DataStructure 
 * @Description: SqDoubleStack
 * @Date: 2018-04-09 22:17:48 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-09 22:26:16
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

bool Push(SqDoubleStack *S, SElemType e, int stackNumber);
bool Pop(SqDoubleStack *S, SElemType *e, int stackNumber);

bool Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)
    {
        return false;
    }
    if (1 == stackNumber)
    {
        S->data[++S->top1] = e;
    }
    else if (2 == stackNumber)
    {
        S->data[--S->top2] = e;
    }
}

bool Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (1 == stackNumber)
    {
        if (-1 == S->top1)
            return false;
        *e = S->data[S->top1--];
    }
    else if (2 == stackNumber)
    {
        if (MAXSIZE == S->top2)
            return false;
        *e = S->data[S->top2++];
    }
    return true;
}
