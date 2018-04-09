/*
 * @Author: endinferno.DataStructure 
 * @Description: Fibonacci sequence
 * @Date: 2018-04-09 23:02:06 
 * @Last Modified by: endinferno.DataStructure
 * @Last Modified time: 2018-04-09 23:03:47
 */

#include <stdio.h>

#define CYCLE 0
#define RECURSIVE !CLCLE

#if CYCLE
int main()
{
    int i;
    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("%d", a[0]);
    printf("%d", a[1]);
    for (i = 2; i < 40; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d", a[i]);
    }
    return 0;
}
#elif RECURSIVE
int Fbi(int i)
{
    if (i < 2)
    {
        return i == 0 ? 0 : 1;
    }
    return Fbi(i - 1) + Fbi(i - 2);
}
int main()
{
    int i;
    for (i = 0; i < 40; i++)
    {
        printf("%d", Fbi(i));
    }
    return 0;
}

#endif