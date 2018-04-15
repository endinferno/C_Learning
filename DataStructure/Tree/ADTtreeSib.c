/*
 * @Author: endinferno.DataStructure 
 * @Description: ADT Tree (Sib)
 * @Date: 2018-04-15 08:48:18 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-15 08:50:27
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
