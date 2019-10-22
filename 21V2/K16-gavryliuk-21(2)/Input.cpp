#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

int main()
{
	char filename[30];
	int n;

	cout << "Enter name for a file you want to create: " << endl;
	cin >> filename;

	ofstream fout(filename, ios::app);

	cout << "Enter length of the array: " << endl;
	cin >> n;

	cout << "Your array will be filled with random numbers" << endl;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		fout << (rand() % 9999) << ' ';

	system("pause");

	return 0;
}