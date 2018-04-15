/*
 * @Author: endinferno.DataStructure 
 * @Description: ADT Tree (Children)
 * @Date: 2018-04-15 08:27:49 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 08:47:06
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;
typedef struct
{
    TElemType data;
    ChildPtr firstchild;
} CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
} CTree;

bool InitTree(CTree *T);
bool DestroyTree(CTree *T);

bool InitTree(CTree *T)
{
    T = (CTree *)malloc(sizeof(CTree));
    if (!T)
    {
        fprintf(stderr, "Error: Failed to Malloc Memory.\n");
        return false;
    }
    T->n = 0;
    T->r = 0;
    return true;
}

bool DestroyTree(CTree *T)
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