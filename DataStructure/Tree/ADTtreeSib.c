/*
 * @Author: endinferno.DataStructure 
 * @Description: ADT Tree (Sib)
 * @Date: 2018-04-15 08:48:18 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 09:52:22
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TElemType;
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;

bool InitTree(CSTree T);
bool DestroyTree(CSTree T);
bool TreeEmpty(CSTree T);

bool InitTree(CSTree T)
{
    T = (CSNode *)malloc(sizeof(CSNode));
    if (!T)
    {
        fprintf(stderr, "Error: Failed to Malloc Memory.\n");
        return false;
    }
    T->rightsib = NULL;
    T->firstchild = NULL;
    return true;
}

bool DestroyTree(CSTree T)
{
    if (!T)
    {
        fprintf(stderr, "Error: Failed to free nullptr.\n");
        return false;
    }
    free(T);
    T = NULL;
    return true;
}

bool TreeEmpty(CSTree T)
{
    return NULL == T;
}