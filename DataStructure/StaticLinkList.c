#include <stdio.h>

#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];
