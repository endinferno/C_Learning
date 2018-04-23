/*
 * @Author: endinferno.DataStructure 
 * @Description: 
 * @Date: 2018-04-23 14:46:16 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-23 15:07:43
 */
/*
 * @Author: endinferno.DataStructure
 * @Description: ADTString
 * @Date: 2018-04-11 20:17:10
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-14 11:12:08
 */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct
{
    ElemType string[MAXSIZE];
    size_t length;
} String;

void InitStr(String *S);
size_t LengthStr(String S);
size_t LengthChrArray(char *str);
bool ClearStr(String *S);
bool IsEmptyStr(String S);
bool AssignStr(String *T, char *str);
void PrintStr(String S);
void CopyStr(String *dst, String src);
void ConcatStr(String *T, String S1, String S2);
int CompareStr(String S, String T);
String SubStr(String S, size_t pos, size_t len);
String CreateEmptyStr();
size_t IndexChr(String S, char c, size_t pos);
size_t IndexStr(String S, String T, size_t pos);

void PrintStr(String S)
{
    for (int i = 0; i < S.length; i++)
        printf("%c", S.string[i]);
    printf("\n");
}
void InitStr(String *S)
{
    S->length = 0;
}
bool AssignStr(String *T, char *str)
{
    if (T == NULL)
    {
        fprintf(stderr, "Error: Failed to Read Null.\n");
        return false;
    }
    T->length = LengthChrArray(str);
    for (int i = 0; i < T->length; i++)
        T->string[i] = str[i];
    return true;
}
size_t LengthChrArray(char *str)
{
    int len = 0;
    while (str[len++] != '\0')
        ;
    return --len;
}
size_t LengthStr(String S)
{
    return S.length;
}
bool ClearStr(String *S)
{
    if (S == NULL)
    {
        fprintf(stderr, "Error: Can not Read Null.\n");
        return false;
    }
    S->length = 0;
    return true;
}
bool IsEmptyStr(String S)
{
    return 0 == S.length;
}
void CopyStr(String *dst, String src)
{
    dst->length = src.length;
    for (int i = 0; i < dst->length; i++)
        dst->string[i] = src.string[i];
}
void ConcatStr(String *T, String S1, String S2)
{
    T->length = S1.length + S2.length;
    for (int i = 0; i < T->length; i++)
    {
        if (i < S1.length)
            T->string[i] = S1.string[i];
        else
            T->string[i] = S2.string[i - S1.length];
    }
}
int CompareStr(String S, String T)
{
    int len = S.length > T.length ? T.length : S.length;
    for (int i = 0; i < len; i++)
    {
        if (S.string[i] > T.string[i])
            return 1;
        else if (S.string[i] < T.string[i])
            return -1;
        else
            continue;
    }
    if (S.length > T.length)
        return 1;
    else if (S.length < T.length)
        return -1;
    else
        return 0;
}
String CreateEmptyStr()
{
    String S;
    InitStr(&S);
    return S;
}
String SubStr(String S, size_t pos, size_t len)
{
    if (pos + len > S.length + 1)
    {
        fprintf(stderr, "Error: Out of Limit.\n");
        return CreateEmptyStr();
    }
    String T;
    T.length = len;
    for (int i = pos - 1; i < pos + len - 1; i++)
        T.string[i - pos + 1] = S.string[i];
    return T;
}
size_t IndexChr(String S, char c, size_t pos)
{
    for (int i = pos - 1; i < S.length; i++)
    {
        if (S.string[i] == c)
            return i + 1;
    }
    return 0;
}
size_t IndexStr(String S, String T, size_t pos)
{
    if (pos < 1 || S.length < T.length)
    {
        fprintf(stderr, "Error: Out of Limit.\n");
        exit(1);
    }
    for (int i = pos - 1; i <= S.length - T.length; i++)
    {
        int u = 0;
        int t = i;
        while (u < T.length)
        {
            if (S.string[t] == T.string[u])
            {
                t++;
                u++;
                if (u == T.length)
                    return i + 1;
            }
            else
                break;
        }
    }
    return 0;
}