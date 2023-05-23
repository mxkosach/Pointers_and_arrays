#include <iostream>
#include <iomanip>
#include "myfunctions.h"
using namespace std;

void myswap(int*, int*);
void fun16(double a, double b, double c, double d, double* p, double* q);
void myout(double a, double b);

void arrcpy(int* Y, int* X, int nx);	//17
void arrCopy(double* Y, double* X, int nx);


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	{
		cout << "\n=== ������� 1 ================\n"; cout.flags(0);
		int n, * p = &n;
		*p = 12;
		cout << "2) �������� n = " << n << ", ����� n = " << &n << endl;
		cout << "3) �������� n = " << *p << ", ����� n = " << p << endl;
		cout << "4) ����� p = " << &p << endl;
	}

	{
		cout << "\n=== ������� 2 ================\n"; cout.flags(0);
		int n, * p = &n;
		int* q; q = p;
		//int m = &n;	//������: ������������ ����������� ��������� ��������
		//float* r = 100;	//������: ������������ ��������� ����������� ��������
		//q = 200;	//������: ������������ ��������� ����������� ��������
		//double* u, x = *u;	//������: ������������� ���������� ������
		char* s, * t;
		//s = &x;	t = &n;	//������: ������������ ��������� ������ ������� ����
	}

	{
		cout << "\n=== ������� 3 ================\n"; cout.flags(0);
		double x = 37.2095;
		char* p;
		p = (char*)&x;
		p += 7;
		cout << "�������� ������������ x = " << x << ":\n";
		for (int i = 0; i < 8; i++)
		{
			binout(*p, ' ');
			p--;
		}
		cout << endl;
	}

	{
		cout << "\n=== ������� 4 ================\n"; cout.flags(0);
		int a = 3, b = 7;
		cout << setw(25) << left << "��������� ������: " << a << ' ' << b << endl;
		myswap(&a, &b);
		cout << setw(25) << left << "��������� ������������: " << a << ' ' << b << endl;
	}

	{
		cout << "\n=== ������� 5 ================\n"; cout.flags(0);
		double* p = new double(1.25), * q = new double(2.75);
		if (!p || !q)
		{
			cout << "\n������! ������������ ������.\n";
			system("pause");
			exit(1);
		}
		cout << "��������� p �������� ������ " << &p
			<< ", ���������� ����� " << *p << endl;
		cout << "��������� q �������� ������ " << &q
			<< ", ���������� ����� " << *q << endl;
		delete p; delete q;
		cout << "���������� ���������� ������������ ������ �����������.\n";
	}

	{
		cout << "\n=== ������� 6a ================\n"; cout.flags(0);
		const int nz = 30; double Z[nz];
		double* p = Z, * q = &Z[10], * r = &Z[20];
		for (int i = 0; i < 10; i++)
		{
			p[i] = rand() % 10 + rand() % 1000 / 1000.;
			q[i] = 10 + rand() % 90 + rand() % 100 / 100.;
			r[i] = 100 + rand() % 900 + rand() % 10 / 10.;
		}
		cout << fixed << setprecision(3);
		for (int i = 0; i < 10; i++)
			cout << setw(7) << p[i];

		cout << endl << setprecision(2);
		for (int i = 0; i < 10; i++)
			cout << setw(7) << q[i];

		cout << endl << setprecision(1);
		for (int i = 0; i < 10; i++)
			cout << setw(7) << r[i];
		cout << endl;
	}

	{
		cout << "\n=== ������� 6b ================\n"; cout.flags(0);
		const int nz = 30; double Z[nz];
		double* p = Z, * q = &Z[10], * r = &Z[20];

		myrnd(p, 10, 0, 9.999, 3); myout(p, 10, 0, 7, 3);
		myrnd(q, 10, 10, 99.99, 2); myout(q, 10, 0, 7, 2);
		myrnd(r, 10, 100, 999.9, 1); myout(r, 10, 0, 7, 1);

	}

	{
		cout << "\n=== ������� 7 ================\n"; cout.flags(0);
		const int nrows = 6, ncols = 10;
		double M[nrows][ncols];
		myrnd(M[0], nrows * ncols, 0.5, 4.5, 1);
		cout << "�� ��������������:\n";
		myout(M[0], nrows * ncols, ncols, nrows, 1);
		for (int i = 0; i < nrows; i++)
			mysrt(M[i], ncols, i % 2);
		cout << "����� ��������������:\n";
		myout(M[0], nrows * ncols, ncols, nrows, 1);
	}

	{
		cout << "\n=== ������� 8 ================\n"; cout.flags(0);
		const int nrows = 6, ncols = 10;
		double M[nrows][ncols];
		myrnd(M[0], nrows * ncols, -9.99, 9.99, 2);
		myout(M[0], nrows * ncols, ncols, nrows, 2);
		cout << "�������� �������� ��������:\n";
		double A[nrows];
		for (int j = 0; j < ncols; j++)
		{
			for (int i = 0; i < nrows; i++)
				A[i] = M[i][j];
			cout << setw(7) << A[mymax(A, nrows)] - A[mymin(A, nrows)];
		}
		cout << endl;
	}

	{
		cout << "\n=== ������� 9 ================\n"; cout.flags(0);
		int nd = 5;
		cout << "������ ������������� �������: " << nd << endl;
		double* D = new double[nd];
		if (!D)
		{
			cout << "\n������! ������������ ������.";
			system("pause");
			return 1;
		}
		myrnd(D, nd, 0, 9.99, 2);
		for (int i = 0; i < nd; i++)
		{
			cout << "D[" << i << "] = " << fixed << setprecision(2) << D[i]
				<< " (����� " << &D[i] << ")\n";
		}
		cout << "������ ������� D = " << sizeof(D) / sizeof(D[0]) << " ?\n";
		delete[]D;
		cout << "���������� ������������� ������� ������ �����������\n";
	}

	{
		cout << "\n=== ������� 10 ================\n"; cout.flags(0);
		int nd = 60;
		int* D = new int[nd];
		myrnd(D, nd, -9, 9);
		myout(D, nd, 20, 3);
		int m = -5, n = 5;
		int* p = D, * end = D + nd;

		while (p < end)
		{
			if (*p == m)
				break;
			p++;
		}

		int* q = end - 1;
		while (q >= D)
		{
			if (*q == n)
				break;
			q--;
		}
		if (p < end && q >= D)
		{
			cout << "������ ������� ����� �������� " << m << " = " << p - D << endl;
			cout << "������ ������� ������ �������� " << n << " = " << q - D << endl;
			cout << "������� " << (p < q ? m : n) << " ���������� ����� � ������ �������\n";
		}
		delete[]D;
	}

	{
		cout << "\n=== ������� 11 ================\n"; cout.flags(0);
		const int nx = 10;
		int X[nx];
		myrnd(X, nx, -99, 99);
		cout << "������ X: ";
		myout(X, nx);

		int s1 = 0, s2 = 0, s3 = 0;
		for (int i = 0; i < nx; i++)
			s1 += X[i];
		cout << "s1 = " << s1 << endl;

		for (int i = 0; i < nx; i++)
			s2 += *(X + i);
		cout << "s2 = " << s2 << endl;

		for (int* p = X, *end = X + nx; p < end; p++)
			s3 += *p;
		cout << "s3 = " << s3 << endl;

		cout << "������� ��������� >10: ";
		for (int* p = X, i = 0, *end = X + nx; p < end; p++, i++)
			if (*p > 10)
				cout << setw(3) << i;
		cout << endl;
	}

	{
		cout << "\n=== ������� 12 ================\n"; cout.flags(0);
		const int nr = 5;
		int M[5][5];
		myrnd(M[0], nr * nr, -9, 9);
		cout << "������� M:\n";
		myout(M[0], nr * nr, nr, nr);
		int sumP = 0, sumN = 0;
		for (int* p = M[0], *end = p + nr * nr; p < end; p++)
			if (*p > 0)
				sumP += *p;
			else
				sumN += *p;
		cout << "����� ������������� ��������� = " << setw(3) << sumP << endl;
		cout << "����� ������������� ��������� = " << setw(3) << sumN << endl;

		int max = M[0][0], imax = 0;
		for (int* p = &M[1][1], i = 1, *end = M[0] + nr * nr; p < end; p += nr + 1, i++)
			if (*p > max)
			{
				max = *p;
				imax = i;
			}
		cout << "�������� ������� ��������� M[" << imax << "][" << imax << "] = " << max << endl;
	}

	{
		cout << "\n=== ������� 13 ================\n"; cout.flags(0);
		cout << "���������\n";
	}

	{
		cout << "\n=== ������� 14 ================\n"; cout.flags(0);
		int n1 = 171, n2 = -94, * pn1 = &n1, * pn2;
		float f1 = 1.6, f2 = 2.7, * pf1 = &f2, * pf2;
		short s1 = -54, s2 = 130, * ps1 = &s1, * ps2;
		char c1 = 'A', c2 = 'B', * pc1 = &c2, * pc2;
		double d1 = 0.7, d2 = 4.8, * pd1 = &d2, * pd2;
		//ps1 = s1;		//������: ������������ ��������� ����������� ��������
		//f1 = pf1;		// ������: ������������ ����������� ��������� ��������
		//pc1 = pd2;	//������: ������������ ��������� ������ ������� ����
		//n1 = *pn2;	//������: ������������� ���������� ������
		//ps1 = &f2;	//������: ������������ ��������� ������ ������� ����
		//d1 = &d2;		// ������: ������������ ����������� ��������� ��������
		//pf1 = pf2;	//������: ������������� ���������� ������
		//pn1 = -19;	//������: ������������ ��������� ����������� ��������
	}

	{
		cout << "\n=== ������� 15 ================\n"; cout.flags(0);
		double d = 370827256.98930174;
		cout << "d = " << d << endl;

		char* p;
		p = (char*)&d;
		p += 4;
		cout << "���� �4 = ";
		binout(*p);
	}

	{
		cout << "\n=== ������� 16 ================\n"; cout.flags(0);
		double a = 3, b = -5, c = 7, d = 4, * p = &a, * q = &b;
		cout << "(" << a << (b > 0 ? " + " : " - ") << abs(b) << "i)("
			<< c << (d > 0 ? " + " : " - ") << abs(d) << "i) = ";
		fun16(a, b, c, d, p, q);
		myout(*p, *q);
	}

	{
		cout << "\n=== ������� 17 ================\n"; cout.flags(0);
		int nx = 50, * X = new int[nx];
		int nt = 50, * T = new int[nt];
		if (!X || !T)
		{
			cout << "\n������! ������������ ������.";
			system("pause");
			return 1;
		}
		myrnd(X, nx, 100, 999);
		cout << "�������� ������:\n";
		myout(X, nx, 10, 5);

		arrcpy(T, X, 10);
		for (int i = 0; i < 4; i++)
		{
			int n0 = 10 * i, n1 = 10 * i + 10;
			arrcpy(&X[n0], &X[n1], 10);
		}
		arrcpy(&X[40], T, 10);
		cout << "�������� ������:\n";
		myout(X, nx, 10, 5);
		delete[]X;
		delete[]T;
	}

	{
		cout << "\n=== ������� 18 ================\n"; cout.flags(0);
		const int nr = 9; double M[nr][nr];
		myrnd(M[0], nr * nr, 10, 99.99, 2);
		cout << "�������� ������:\n";
		myout(M[0], nr * nr, nr, nr, 2);
		const int na = nr * (nr - 1) / 2;
		double* A = new double[na];
		int n = 0;
		for (int i = 0; i < nr; i++)
		{
			arrCopy(&A[n], &M[i][i + 1], nr - i - 1);
			n += nr - i - 1;
		}
		cout << "�������� ������:\n";
		myout(A, na, sqrt(na), sqrt(na), 2);
		delete[]A;
	}

	{
		cout << "\n=== ������� 19 ================\n"; cout.flags(0);
		int nc = 50;
		double* C = new double[nc];
		if (!C)
		{
			cout << "\n������! ������������ ������.";
			system("pause");
			return 1;
		}
		myrnd(C, nc, 0, 2, 1);
		cout << "�������� ������:\n";
		myout(C, nc, 10, 5, 1);

		cout << "���������� �������� �������: ";
		for (double* p = C, *end = C + nc; p < end; p++)
		{
			if (*p < 0)
				continue;
			int n = 0;
			for (double* q = p+1; q < end; q++)
				if (*q == *p)
				{
					*q = -1;
					n++;
				}
			if (n==0)
				cout << setw(5) << *p;
		}
		delete[]C;
		cout << endl;
	}


	{
		cout << "\n=== ������� 20 ================\n"; cout.flags(0);
		const int nr = 5;
		double M[nr][nr];
		myrnd(M[0], nr* nr, -9.9, 9.9, 1);
		cout << "�������� �������:\n";
		myout(M[0], nr* nr, nr, nr, 1);
		double max = -10, sum = 0;

		for (double* p = M[0]+nr-1, *end = M[nr - 1]; p <= end; p += nr-1 )
		{
			sum += *p;
			if (*p > max)
				max = *p;
		}
		cout << "����� ��������� �������� ��������� ������� = " << sum << endl
			<< "������������ ������� �������� ��������� ������� = " << max << endl;
	}


	cout << endl; system("pause");
	return 0;
}



void myswap(int* m, int* n)
{
	if (*m != *n)
	{
		int t = *m; *m = *n; *n = t;
	}
}

void fun16(double a, double b, double c, double d, double* p, double* q)
{
	*p = a * c - b * d;
	*q = c * b + a * d;
}

void myout(double a, double b)
{
	cout << a << (b > 0 ? " + " : " - ") << abs(b) << "i";
}

void arrcpy(int* Y, int* X, int nx)
{
	for (int i = 0; i < nx; i++)
		Y[i] = X[i];
}

void arrCopy(double* Y, double* X, int nx)
{
	for (int i = 0; i < nx; i++)
		Y[i] = X[i];
}
