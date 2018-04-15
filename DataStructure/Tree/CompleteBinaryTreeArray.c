/*
 * @Author: endinferno.DataStructure 
 * @Description: Complete Binary Tree (Array)
 * @Date: 2018-04-15 09:19:22 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 09:27:45
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct
{
    TElemType data[MAX_TREE_SIZE];
    int n;
} CBTree;

bool InitTree(CBTree *T);
bool DestroyTree(CBTree *T);

bool InitTree(CBTree *T)
{
    T = (CBTree *)malloc(sizeof(CBTree));
    if(!T)
    {
        fprintf(stderr,"Error: Failed to Malloc Memory.\n");
        return false;
    }
    T->n = 0;
    return true;
}

bool DestroyTree(CBTree *T)
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
