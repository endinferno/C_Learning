/*
 * @Author: endinferno.DataStructure 
 * @Description: ADTString
 * @Date: 2018-04-11 20:17:10 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-12 00:05:39
 */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct
{
    char *data;
    int length;
} String;

bool StrAssign(String T, char *str);
bool StrCopy(String T, String S);
int StrLength(String S);
bool StringEmpty(String S);
bool ClearString(String S);
int StrCompare(String S, String T);
bool Concat(String T, String S1, String S2);

bool StrAssign(String T, char *str)
{
    if (str == NULL)
        return false;
    int len = 0;
    while (str[len] != '\0')
        len++;
    T.length = len;
    T.data = (char *)malloc(T.length * sizeof(char));
    if (T.data == NULL)
    {
        fprintf(stderr, "Error: Failed to malloc memory.\n");
        exit(1);
    }
    int i = 0;
    while (str[i] != 0)
        T.data[i] = str[i];
    return true;
}

int StrLength(String S)
{
    return S.length;
}

bool StrCopy(String T, String S)
{
    if (StringEmpty(S))
        return false;
    T.length = S.length;
    T.data = (char *)malloc(T.length * sizeof(char));
    if (T.data == NULL)
    {
        fprintf(stderr, "Error: Failed to malloc memory.\n");
        exit(1);
    }
    int i = 0;
    while (i < T.length)
        T.data[i] = S.data[i];
    return true;
}

bool StringEmpty(String S)
{
    return 0 == S.length;
}

bool ClearString(String S)
{
    free(S.data);
    S.length = 0;
}

int StrCompare(String S, String T)
{
    int i = 0;
    while (i < S.length || i < T.length)
    {
        if (S.data[i] > T.data[i])
            return 1;
        else if (S.data[i] < T.data[i])
            return -1;
        else
            i++;
    }
    return 0;
}

bool Concat(String T, String S1, String S2)
{
    T.length = S1.length + S2.length;
    T.data = (char *)malloc(T.length * sizeof(char));
    if (T.data == NULL)
    {
        fprintf(stderr, "Error: Failed to malloc memory.\n");
        exit(1);
    }
    for (int i = 0; i < S1.length; i++)
    {
        T.data[i] = S1.data[i];
    }
    for (int i = S1.length; i < T.length; i++)
    {
        T.data[i] = S2.data[i];
    }
    return true;
}

