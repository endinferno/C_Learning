/*
 * @Author: endinferno.DataStructure 
 * @Description: SqDoubleStack
 * @Date: 2018-04-09 22:17:48 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-09 22:20:16
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

bool Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    
}