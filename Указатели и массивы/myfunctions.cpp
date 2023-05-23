#include <iostream>
#include <iomanip>
#include "myfunctions.h"
using namespace std;

void binout(char n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned char m = n, k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

unsigned int myrnd()
{
	unsigned int res;
	char* p = (char*)&res;
	for (int i = 0; i < 4; i++)
	{
		*p = rand() % 256;
		p++;
	}
	return res;
}

int myrnd(int a, int b)
{
	if (a > b)
		return 0;
	return a + myrnd() % (b - a + 1);
}

double myrnd(double x, double y, int n)
{
	if (x > y || n < 0)
		return 0;
	double m = pow(10, n);
	int a = x * m, b = y * m;
	return myrnd(a, b) / m;
}

void myrnd(int* M, int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(a, b);
}

void myrnd(double* M, int size, double x, double y, int n)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(x, y, n);
}

void myout(int* M, int size, int nc, int nw)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(double* M, int size, int nc, int nw, int nq)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setw(nw) << setprecision(nq) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void mysrt(int* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

void mysrt(double* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

int mymax(int* M, int size)
{
	int imax = 0;
	int max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

int mymax(double* M, int size)
{
	int imax = 0;
	double max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

int mymin(int* M, int size)
{
	int imin = 0;
	int min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}

int mymin(double* M, int size)
{
	int imin = 0;
	double min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}