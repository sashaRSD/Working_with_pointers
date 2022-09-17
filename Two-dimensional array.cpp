#include <conio.h>
#include <random>
#include <locale.h>
#include <ctime>
#include <Windows.h>

#define N 3
int n;
int* q[N], ** w[N], * e[N];
int a[N][N];
const char* namefirst[5] = { "������������ ��� ����������� ������� ��������.", "������������ ��� ����������� ������� ����� �������.", "������������ ��� ����������� ������� �������� �������.", "�����", NULL };
const char* namesecond[4] = { "������������ �������", "����������� �������", NULL };

int menu(char* name[]);
int maxchstlb(int** w, int n);
int minchstlb(int** w, int n);
int maxchstr(int** w, int n);
int maxchstr(int** w, int n);
int maxch(int* e, int n);
int minch(int* e, int n);
void vividmass(int** w, int n);
void vvodmass(int n);
void maxminchisstlb(bool flag);
void maxminchisstr(bool flag);
void maxminchis(bool flag);
void glavmenu(bool flag);

int menu(const char* name[])
{
	const char** tmp = name;
	int i = 0;
	while (*tmp) printf("\n%d %s", i++, *tmp++);
	return i;
}

int maxchstlb(int** w, int n)
{
	int max = 0, stlb = 0, i = 0;
	int** tmp;
	tmp = w;
	do
	{
		printf("\n������������ ������� ������� �����: ");
		scanf_s("%d", &stlb);
	} while ((stlb < 1) || (stlb > n));
	stlb--;

	while (*tmp != NULL)
	{
		if (*(*(w + i) + stlb) > max) max = *(*(w + i) + stlb);
		i++; tmp++;
	}
	return max;
}

int minchstlb(int** w, int n)
{
	int min = 10, stlb = 0, i = 0;
	int** tmp;
	tmp = w;
	do
	{
		printf("\n����������� ������� ������� �����: ");
		scanf_s("%d", &stlb);
	} while ((stlb < 1) || (stlb > n));
	stlb--;

	while (*tmp != NULL)
	{
		if (*(*(w + i) + stlb) < min) min = *(*(w + i) + stlb);
		i++; tmp++;
	}
	return min;
}

int maxchstr(int** w, int n)
{
	int max = 0, str = 0, i = 0;
	int** tmp;
	tmp = w;
	do
	{
		printf("\n������������ ������� ������ �����: ");
		scanf_s("%d", &str);
	} while ((str < 1) || (str > n));
	str--;

	while (*tmp != NULL)
	{
		if (*(*(w + str) + i) > max) max = *(*(w + str) + i);
		i++; tmp++;
	}
	return max;
}

int minchstr(int** w, int n)
{
	int min = 10, str = 0, i = 0;
	int** tmp;
	tmp = w;
	do
	{
		printf("\n����������� ������� ������ �����: ");
		scanf_s("%d", &str);
	} while ((str < 1) || (str > n));
	str--;

	while (*tmp != NULL)
	{
		if (*(*(w + str) + i) < min) min = *(*(w + str) + i);
		i++; tmp++;
	}
	return min;
}

int maxch(int* e, int n)
{
	int max = 0, i = 0;
	int* tmp;
	tmp = e;
	while (*tmp != NULL)
	{
		if (e[i] > max) max = e[i];
		i++; tmp++;
	}
	return max;
}

int minch(int* e, int n)
{
	int min = 10, i = 0;
	int* tmp;
	tmp = e;
	while (*tmp != NULL)
	{
		if (e[i] < min) min = e[i];
		i++; tmp++;
	}
	return min;
}

void vividmass(int** w, int n)
{
	printf(" ��������� ������, ��������� � ������� ������� random: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", *(*(w + i) + j));
		}
		printf("\n");
	}
}

void vvodmass(int n)
{
	int buf;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			do
			{
				buf = rand() % 10;
			} while (buf == 0);
			a[i][j] = buf;
		}
	}
	for (int i = 0; i < N; i++)
		q[i] = a[i];
}

void maxminchisstlb(bool flag)
{
	int vv;
	while (flag != false)
	{
		printf("\n\n ������������ ��� ����������� ������� �������?");
		menu(namesecond);
		printf("\n ��� �����: ");
		scanf_s("%d", &vv);
		{
			switch (vv)
			{
			case 0: system("cls"); vividmass(q, n); printf("\n ������������ ����� � �������: %d", maxchstlb(q, n)); flag = false;  break;
			case 1:  system("cls"); vividmass(q, n); printf("\n ����������� ����� � �������: %d", minchstlb(q, n)); flag = false; break;
			default: system("cls"); vividmass(q, n); printf(" �������� ��������!!! ��������� �������!"); break;
			}
		}
	}
}

void maxminchisstr(bool flag)
{
	int vv;
	while (flag != false)
	{
		printf("\n\n ������������ ��� ����������� ������� ������?");
		menu(namesecond);
		printf("\n ��� �����: ");
		scanf_s("%d", &vv);
		{
			switch (vv)
			{
			case 0: system("cls"); vividmass(q, n); printf("\n ������������ ����� � ������: %d", maxchstr(q, n)); flag = false;  break;
			case 1:  system("cls"); vividmass(q, n); printf("\n ����������� ����� � ������: %d", minchstr(q, n)); flag = false; break;
			default: system("cls"); vividmass(q, n); printf(" �������� ��������!!! ��������� �������!"); break;
			}
		}
	}
}

void maxminchis(bool flag)
{
	int vv;
	while (flag != false)
	{
		printf("\n\n ������������ ��� ����������� ������� �������?");
		menu(namesecond);
		printf("\n ��� �����: ");
		scanf_s("%d", &vv);
		{
			switch (vv)
			{
			case 0: system("cls"); vividmass(q, n); printf("\n������������ ����� � �������: %d", maxch((int*)*a, n)); flag = false;  break;
			case 1:  system("cls"); vividmass(q, n); printf("\n����������� ����� � �������: %d", minch((int*)*a, n)); flag = false; break;
			default: system("cls"); vividmass(q, n); printf(" �������� ��������!!! ��������� �������!"); break;
			}
		}
	}
}

void glavmenu(bool flag)
{
	int vv;
	while (flag != false)
	{
		printf("\n\n ���� ���������:");
		menu(namefirst);
		printf("\n ��� �����: ");
		scanf_s("%d", &vv);
		{
			switch (vv)
			{
			case 0: system("cls"); vividmass(q, n); maxminchis(true); break;
			case 1:  system("cls"); vividmass(q, n); maxminchisstr(true); break;
			case 2: system("cls"); vividmass(q, n); maxminchisstlb(true); break;
			case 3: flag = false; printf(" ��� ���������� ������� ����� �������!"); break;
			default: system("cls"); vividmass(q, n); printf(" �������� ��������!!! ��������� �������!"); break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	n = N;
	vvodmass(n);
	vividmass(q, n);
	glavmenu(true);

	_getch();
	return 0;
}