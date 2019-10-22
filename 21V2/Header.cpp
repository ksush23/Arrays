#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Header.h"

using namespace std;

Array::Array(): N(C), p(new int[N]), M(0)
{
}
Array::~Array()
{
	if (p != NULL)
	{
		delete[]p;
		p = NULL;
	}
}
bool operator >> (istream& is, Array& arr)
{
	arr.M = 0;

	while (1)
	{
		if (&is == &cin)
			cout << "Enter p[" << arr.M << "] element of the array: " << endl;
		if (is >> arr.p[arr.M])
			++arr.M;
		else
			break;
		if (arr.M == arr.N)
			arr.length_up();
	}
	close(is);
	return (arr.M > 0);
}
void operator << (ostream& os, const Array& arr) 
{
	int k = 0;
	while (k < arr.M)
	{
		os << right;
		os << setw(15) << setfill(' ') << arr.p[k++];
		if (k % 4 == 0)
			os << endl;
	}
	os << endl;
}
void close(istream & s)
{
	if (&s == &cin)
	{
		s.clear(); s.sync(); s.ignore();
	}
	else
		((ifstream&)s).close();
}
void close(ostream & s)
{
	if (&s != &cout)
	{
		((ofstream&)s).close();
	}
}
bool Array::edit_array()
{
	int c;
	bool ok1 = 1;
	cout << "Enter a value you want to enter before first prime number(or at the end if there aren't any): " << endl;
	cin >> c;
	if (M == N)
		length_up();
	++M;
	bool ok = 1;
	for (int i = 0; i < M - 1; i++)
	{
		if (is_prime(p[i]))
		{
			for (int j = M - 1; j >= i; j--)
				p[j + 1] = p[j];
			p[i] = c;
			ok = 0;
			break;
		}
	}
	if (ok)
		p[M - 1] = c;
	return 1;
}
bool is_prime(int a)
{
	if (a == 0 || a == 1)
		return 0;
	for (int j = 2; j * j < a + 1; j++)
		if (a % j == 0 && a != j)
			return 0;
	return 1;
}
void Array::length_up()
{
	if (N == 0)
	{
		N = C;
		p = new int[N];
	}
	else
	{
		int K = N;
		int *p1;
		p1 = p;
		bool ok = 1;
		do
		{
			try { p = new int[N + K]; }
			catch (bad_alloc)
			{
				K /= 2;
				ok = 0;
			}
		} while (!ok);
		if (K == 0)
		{
			cout << "MEMORY ALLOC : IMPOSSIBLE" << endl;
			return;
		}
		for (int i = 0; i < N; i++)
			p[i] = p1[i];
		delete[]p1;
		p1 = NULL;
		N += K;
		cout << "MEMORY ALLOC: " << "length of the array: " << N << " size of new memory area: " << (sizeof(int) * (N - K)) << endl;
	}
}