/*
 * @Author: endinferno.DataStructure 
 * @Description: Arithmetic
 * @Date: 2018-04-09 23:10:39 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-09 23:11:20
 */

#include <stdio.h>
#include <stdbool.h>

#define EnableStack 1

#if EnableStack

#define MAXSIZE 100

typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

bool Push(SqStack *S, SElemType e);
bool Pop(SqStack *S, SElemType *e);

bool Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        printf("Error: Out of limit.\n");
        return false;
    }
    S->top++;
    S->data[S->top] = e;
    return true;
}

bool Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
    {
        printf("Error: Out of limit.\n");
        return false;
    }
    *e = S->data[S->top];
    S->top--;
    return true;
}

SqStack Operator;
SqStack final;
#endif

int main()
{
    int num;
    char c;
    printf("asd\n");
    printf("test\n");
    char ch;
    while (true)
    {
        int o = scanf("%d", &num);
        int u = scanf("%c", &c);
        if (o != 0)
        {
            Push(&final, num);
        }
        if (u != 0)
        {
            if (c == ')')
            {
                Pop(&Operator, &ch);
            }
            else
            {
                Push(&Operator, c);
            }
        }
        if ('=' == c)
        {
            break;
        }
    }
    return 0;
}
