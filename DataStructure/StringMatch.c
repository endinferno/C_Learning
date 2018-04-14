/*
 * @Author: endinferno.DataStructure 
 * @Description: String Matching
 * @Date: 2018-04-14 11:13:33 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-14 12:14:32
 */

#include <stdio.h>
#include <string.h>

int IndexSimple(char *S, char *T, int pos);
void GetNext(char *str, int *next);

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

void GetNext(char *str, int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < strlen(str))
    {
        if (j == 0 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int IndexKMP(char *S, char *T, int pos)
{
}