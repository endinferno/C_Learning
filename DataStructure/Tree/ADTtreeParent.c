/*
 * @Author: endinferno.DataStructure 
 * @Description: ADT Tree (Parent)
 * @Date: 2018-04-14 23:33:45 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 08:46:02
 */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;
typedef struct PTNode
{
    TElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int r, n;
} PTree;

bool InitTree(PTree *T);
bool DestroyTree(PTree *T);

bool InitTree(PTree *T)
{
    T = (PTree *)malloc(sizeof(PTree));
    if (!T)
    {
        fprintf(stderr, "Error: Failed to Malloc Memory.\n");
        exit(1);
    }
    T->r = 0;
    T->n = 0;
    T->nodes[T->r].parent = -1;
}

bool DestroyTree(PTree *T)
{
    if (T == NULL)
    {
        fprintf(stderr, "Error: Failed to free nullptr.\n");
        return false;
    }
    free(T);
    T = NULL;
    return true;
}
