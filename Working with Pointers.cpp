#include <math.h>
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

#define NK 128
#define NI 8
#define NJ 32

char Buf[NK];
char* pB[NI];
char** pBB[NJ];


void InputTree(char*** pXX, char** pX, char* Buf);
void OutTree(char*** pXXX);
void IputBuf(char* buf);


void InputTree(char*** pXX, char** pX, char* Buf)
{
	int I, J, K, i;
	printf("\n Создаёте кубик из Buf с размерами (I, J, K): \n");
	printf(" I="); scanf_s("%d", &I);
	while (I < 2)
	{
		printf(" Ошибка, I должно быть больше 1. Повторите попытку! \n I=");
		scanf_s("%d", &I);
	}

	printf(" J="); scanf_s("%d", &J);
	while (J < 1)
	{
		printf(" Ошибка, J должно быть больше 0. Повторите попытку! \n J=");
		scanf_s("%d", &J);
	}

	printf(" K="); scanf_s("%d", &K);
	while (K < 0)
	{
		printf(" Ошибка, K должно быть больше 0. Повторите попытку! \n K=");
		scanf_s("%d", &K);
	}

	for (i = 0; i < I * J; i++)
	{
		pX[i] = Buf + i * K;
	}
	pX[i] = NULL;

	for (i = 0; i < I; i++)
	{
		pXX[i] = pX + i * J;
	}
	pXX[i] = NULL;
}

void IputBuf(char* buf)
{
	char c = 'A';
	while (c < 'Z') *buf++ = c++;
}

void OutTree(char*** pXXX)
{
	int I, J, K;
	I = 0;
	char*** tmp = pXXX;
	while (*tmp++) I++;
	J = *(pXXX + 1) - *pXXX;
	K = *(*pXXX + 1) - **pXXX;
	printf("\n Значения, которые получены при разыменовании **pBB: I=%d J=%d K=%d \n", I, J, K);
}


int main()
{
	setlocale(LC_ALL, "RUS");
	IputBuf(Buf);
	InputTree(pBB, pB, Buf);
	OutTree(pBB);

	return 0;
}