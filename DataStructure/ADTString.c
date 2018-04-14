/*
 * @Author: endinferno.DataStructure
 * @Description: ADTString
 * @Date: 2018-04-11 20:17:10
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-14 10:59:09
 */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXSIZE 40

typedef int Status;
typedef int ElemType;

typedef char String[MAXSIZE + 1];

int StrLength(String S);
bool ClearString(String S);
bool StringEmpty(String S);
bool StrCopy(String S, String T);
bool StrAssign(String T, char *str);
bool Concat(String T, String S1, String S2);
int StrCompare(String S, String T);
void StrPrint(String S);
bool SubString(String Sub, String S, int pos, int len);
int Index(String S, String T, int pos);
bool Replace(String S, String T, String V);

bool StrAssign(String T, char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    T[0] = len;
    for (int i = 1; i <= len; i++)
    {
        T[i] = str[i - 1];
    }
    return true;
}

bool StrCopy(String T, String S)
{
    for (int i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return true;
}

bool StringEmpty(String S)
{
    return 0 == S[0];
}

bool ClearString(String S)
{
    S[0] = 0;
    return true;
}

int StrLength(String S)
{
    return S[0];
}

int StrCompare(String S, String T)
{
    for (int i = 1; i <= S[0] && i <= T[0]; i++)
    {
        if (S[i] > T[i])
            return 1;
        else if (S[i] < T[i])
            return -1;
        else
            continue;
    }
    if (S[0] > T[0])
        return 1;
    else if (S[0] < T[0])
        return -1;
    else
        return 0;
}

void StrPrint(String S)
{
    for (int i = 1; i <= S[0]; i++)
    {
        printf("%c", S[i]);
    }
    printf("\n");
}

bool Concat(String T, String S1, String S2)
{
    T[0] = S1[0] + S2[0];
    for (int i = 1; i <= S1[0]; i++)
        T[i] = S1[i];
    for (int i = 1; i <= S2[0]; i++)
        T[i + S1[0]] = S2[i];
    return true;
}

bool SubString(String Sub, String S, int pos, int len)
{
    if (pos < 1 || pos > StrLength(S))
    {
        fprintf(stderr, "Error: Out of limit.\n");
        return false;
    }
    if (len < 0 || len > StrLength(S) - pos + 1)
    {
        fprintf(stderr, "Error: Out of limit.\n");
        return false;
    }
    Sub[0] = len;
    for (int i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];
    return true;
}

int Index(String S, String T, int pos)
{
    for (int i = pos; i <= S[0] - T[0] + 1; i++)
    {
        int u, o = i;
        for (u = 1; u <= T[0]; u++)
        {
            if (S[o] == T[u])
                o++;
            else
                break;
        }
        if (u - 1 == T[0] && S[i + u - 2] == T[u - 1])
        {
            return i;
        }
    }
    return 0;
}

bool Replace(String S, String T, String V)
{
    
}

int main()
{
    String S, T;
    StrAssign(S, "123456789");
    StrAssign(T, "456");

    return 0;
}