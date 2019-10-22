#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;

istream& setIStream(ifstream& f, bool &ok);
ostream& setOStream(ofstream& f);

int main()
{
	bool ok = 1;
	int i = 0;
	Array arr;

	ifstream f; ofstream g;
	istream & s_in = setIStream(f, ok);
	if (ok)
		if (s_in >> arr)
		{
			ostream & s_out = setOStream(g);
			s_out << arr;
			ok = arr.edit_array();
			if (ok)
				s_out << arr;
		}
	system("pause");

	return 0;
}
istream& setIStream(ifstream& f, bool &ok)
{
	int i;
	do 
	{
		cout << "Enter 1 to fill array from file\n" << "Enter 2 to fill values from keyboard\n" << "Enter 9 to quit\n";
		cout << "Enter your number of choice: " << endl;
		cin >> i;
	} while (i != 1 && i != 2 && i != 9);
	if (i == 1)
	{
		cout << "Enter filepath you want to have values from (otherwise they'll be taken from in.txt): " << endl;
		string fN;
		cin.get();
		getline(cin, fN);
		if (fN.length() == 0)
			fN = "in.txt";
		f.open(fN);
		return (istream &)f;
	}
	if (i == 2)
		return cin;
	else
		ok = 0;
}
ostream& setOStream(ofstream& f)
{
	int i;
	do
	{
		cout << "Enter 1 to have results on screen\n" << "Enter 2 to have them in file\n";
		cout << "Enter your number of choice: " << endl;
		cin >> i;
	} while (i != 1 && i != 2);
	if (i == 1)
		return cout;
	else 
	{
		cout << "Enter filepath you want to have your results in (otherwise they'll be in out.txt): " << endl;
		string fN;
		cin.get();
		getline(cin, fN);
		if (fN.length() == 0)
			fN = "out.txt";
		f.open(fN);
		return (ostream &)f;
	}
}