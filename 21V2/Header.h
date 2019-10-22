#pragma once
#include <fstream>

using namespace std;

class Array
{
private:
	static const int C = 100;
	int N;
	int M;
	int *p;
	void length_up();
public:
	Array();
	~Array();
	bool edit_array();
	friend bool operator >> (istream& is, Array& arr);
	friend void operator << (ostream& os, const Array& arr);
};

bool is_prime(int a);
void close(istream & s);
void close(ostream & s);