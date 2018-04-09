/*
 * @Author: endinferno.DataStructure 
 * @Description: SqStack
 * @Date: 2018-04-09 22:11:14 
 * @Last Modified by: endinferno.DataStructure 
 * @Last Modified time: 2018-04-09 22:11:14 
 */


#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

bool Push(SqStack *S, SElemType e);

bool Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE -1)
    {
        return false;
    }
    
}