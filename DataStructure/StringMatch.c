/*
 * @Author: endinferno.DataStructure 
 * @Description: String Matching
 * @Date: 2018-04-14 11:13:33 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-14 14:04:15
 */

#include <stdio.h>
#include <string.h>

int IndexSimple(char *S, char *T, int pos);
void GetNext(char *str, int *next);
int IndexKMP(char *S, char *T);

int IndexSimple(char *S, char *T, int pos)
{
    int i = pos;
    int j = 0;
    while (i < strlen(S) && j < strlen(T))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= strlen(T))
        return i - strlen(T);
    else
        return -1;
}

void GetNext(char *T, int *next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int IndexKMP(char *S, char *T)
{
    int next[10];
    GetNext(T, next);
    int i = 1;
    int j = 1;
    while (i <= strlen(S) && j <= strlen(T))
    {
        if (j == 0 || S[i - 1] == T[j - 1])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > strlen(T))
        return i - (int)strlen(T) - 1;
    return -1;
}