/*
 * @Author: endinferno.DataStructure 
 * @Description: Complete Binary Tree (Link)
 * @Date: 2018-04-15 09:29:31 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 11:37:44
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool InitTree(BiTree T);
bool DestroyTree(BiTree T);
bool TreeEmpty(BiTree T);
void PreOrderTraverse(BiTree T);
void PreOrderTraverse(BiTree T);

bool InitTree(BiTree T)
{
    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T)
    {
        fprintf(stderr, "Error: Failed to Malloc Memory.\n");
        return false;
    }
    T->lchild = NULL;
    T->rchild = NULL;
    return true;
}

bool DestroyTree(BiTree T)
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

bool TreeEmpty(BiTree T)
{
    return NULL == T;
}

void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void CreateTree(BiTree T)
{
    T->data = 0;
    BiTree S;
    BiTree M = T;
    M->data = 0;
    S = (BiTree)malloc(sizeof(BiTNode));
    S->lchild = NULL;
    S->rchild = NULL;
    S->data = 1;
    M->lchild = S;
    
}
