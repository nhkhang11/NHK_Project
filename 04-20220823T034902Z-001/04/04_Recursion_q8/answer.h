#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int cP(int n, int* p, int  s)
{
	return 0;
}
int a2B(int n, int st, int a, int b)
{
	if (n == 0)		return 0;

	if (n < 0)		return 0;

	int i = n % b;
	st++;
	int result = a2B(n / b, st, a, b) + i * pow(a, (st - 2));
	return result;

}
void pA(bool* p, int s)
{
	if (s < 1) return;
	s--;
	pA(p, s);
	cout << p[s] << " ";
}
int pS(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;
	if (n == 1) return 1;
	return 1 + pS(n / 2);
}
int dTB(int n, int st)
{
	if (n == 0)		return 0;

	if (n < 0)		return 0;

	int i = n % 2;
	st++;
	int result = dTB(n / 2, st) + i * pow(10, (st - 2));
	return result;

}
int bTD(int n, int st)
{
	if (n == 0)		return 0;

	if (n < 0)		return 0;

	int i = n % 10;
	st++;
	int result = bTD(n / 10, st) + i * pow(2, (st - 2));
	return result;

}
int bTS(int n, int st)
{
	if (n == 0)		return 0;

	if (n < 0)		return 0;

	int i = n % 10;
	st++;
	int result = bTS(n / 10, st) + i * pow((st - 1), 2);
	return result;
}
int inB(int n)
{
	int d = a2B(n, 1, 2, 10);
	d++;
	return  a2B(d, 1, 10, 2);
}

int fS(int n, int i)
{
	if (pow(i, 2) > n - 1) return i;
	return fS(n, i + 1);
}
void pST(bool* p, int s, int i)
{
	if (i == s) return;
	p[i] = 0;
	i++;
	pST(p, s, i);
}
int b2D(bool* p, int s, int i)
{
	if (s < 1) return 0;

	return p[s - 1] * pow(2, i) + b2D(p, s - 1, i + 1);
}
void d2B(int n, bool* p, int& i)
{
	if (n == 0) return;
	p[i] = n % 2;
	i--;
	d2B(n / 2, p, i);
}
void iB(bool* p, int s)
{
	int d = b2D(p, s, 0);
	d++;
	int i = s - 1;
	d2B(d, p, i);
}
bool eP(bool* p, int s)
{
	if (s == 0) return 1;
	if (!p[s - 1]) return 0;
	return eP(p, s - 1);
}
int b2S(bool* p, int s, int i = 1)
{
	if (s == 0)		return 0;

	return p[s - 1] * pow(i, 2) + b2S(p, s - 1, i + 1);
}
void cE(int n, bool* p, int s, int i, int& c)
{
	if (eP(p, s)) return;
	int d = b2S(p, s);
	iB(p, s);
	if (d == n) c++;
	cE(n, p, s, i, c);
}

int countWaySumOfSquare(int n)
{
	int count = 0;
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	int s = fS(n, 0);
	int c = 0;
	bool* p = new bool[s];
	pST(p, s, 0);
	int i = 0;
	cE(n, p, s, i, c);
	delete[] p;

	return c;
}
/// END  <STUDENT ANSWER>