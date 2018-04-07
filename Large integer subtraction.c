#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void arrayInit();
void arrayReverse();
void adjustFormat();
void getNum1AndNum2();
int isNum1BiggerThanNum2();
int getNumOfZero();
bool hasNegativeLeft();
void process();
void getSubOfDigit();
void getResult();

char strNum1[100];
char strNum2[100];
int num[100];

int main()
{
	arrayInit();
	getNum1AndNum2();
	int res = isNum1BiggerThanNum2();
	arrayReverse();
	switch (res)
	{
	case -1:
	{
		printf("0");
		break;
	}
	case 1:
	{
		getResult(1);
		int i;
		for (i = 100 - getNumOfZero() - 1; i >= 0; i--)
		{
			printf("%d", num[i]);
		}
		break;
	}
	case 0:
	{
		getResult(0);
		printf("-");
		int i;
		for (i = 100 - getNumOfZero() - 1; i >= 0; i--)
		{
			printf("%d", num[i]);
		}
	}
	}
	return 0;
}


void arrayInit()
{
	memset(num, 0, 100);
	memset(strNum1, '0', 100);
	memset(strNum2, '0', 100);
}

void arrayReverse()
{
	int i;
	char c;
	for (i = 0; i < strlen(strNum1) / 2; i++)
	{
		c = strNum1[i];
		strNum1[i] = strNum1[strlen(strNum1) - 1 - i];
		strNum1[strlen(strNum1) - 1 - i] = c;
	}
	for (i = 0; i < strlen(strNum2) / 2; i++)
	{
		c = strNum2[i];
		strNum2[i] = strNum2[strlen(strNum2) - 1 - i];
		strNum2[strlen(strNum2) - 1 - i] = c;
	}
}

void adjustFormat()
{
	int i = 0;
	while (strNum1[i] == '0')
	{
		i++;
	}
	strcpy(strNum1, strNum1 + i);
	i = 0;
	while (strNum2[i] == '0')
	{
		i++;
	}
	strcpy(strNum2, strNum2 + i);
}

void getNum1AndNum2()
{
	fgets(strNum1, 100, stdin);
	if (strNum1[strlen(strNum1) - 1] == '\n')
		strNum1[strlen(strNum1) - 1] = '\0';
	fgets(strNum2, 100, stdin);
	if (strNum2[strlen(strNum2) - 1] == '\n')
		strNum2[strlen(strNum2) - 1] = '\0';
	adjustFormat();
}

int isNum1BiggerThanNum2()
{
	if (strlen(strNum1) > strlen(strNum2))
		return 1;
	else if (strlen(strNum1) < strlen(strNum2))
		return 0;
	else
	{
		int i;
		for (i = 0; i < strlen(strNum1); i++)
		{
			if (strNum1[i] > strNum2[i])
			{
				return 1;
			}
			else if (strNum1[i] < strNum2[i])
			{
				return 0;
			}
			else
			{
			}
		}
		return -1;
	}
}

int getNumOfZero()
{
	int i = 100;
	while (i >= 1)
	{
		if (num[i - 1] != 0)
		{
			break;
		}
		i--;
	}
	return 100 - i;
}

bool hasNegativeLeft()
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (num[i] < 0)
		{
			return true;
		}
	}
	return false;
}

void process()
{
	int i;
	for (i = 100 - 1; i >= 0; i--)
	{
		if (!hasNegativeLeft())
		{
			break;
		}
		int u = i;
		if (num[i] < 0)
		{
			num[i] += 10;
			while (num[u + 1] == 0)
			{
				num[u + 1] += 9;
				u++;
			}
			num[u + 1]--;
		}
	}
}

void getSubOfDigit(int param)
{
	size_t i = 0;
	if (1 == param)
	{
		while (strNum2[i] != '\0')
		{
			num[i] = strNum1[i] - strNum2[i];
			i++;
		}
		if (strNum1[i] != '\0')
		{
			while (strNum1[i] != '\0')
			{
				num[i] = strNum1[i] - '0';
				i++;
			}
		}
		for (i = strlen(strNum1); i < 100; i++)
		{
			num[i] = 0;
		}
	}
	else if (0 == param)
	{
		while (strNum1[i] != '\0')
		{
			num[i] = strNum2[i] - strNum1[i];
			i++;
		}
		if (strNum2[i] != '\0')
		{
			while (strNum2[i] != '\0')
			{
				num[i] = strNum2[i] - '0';
				i++;
			}
		}

		for (i = strlen(strNum2); i < 100; i++)
		{
			num[i] = 0;
		}
	}
}

void getResult(int param)
{
	getSubOfDigit(param);
	process();
}