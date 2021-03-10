#include <iostream>
#include <iomanip>
#include <time.h>
#include <algorithm>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int n, const int k);
void Sort(int** a, const int rowCount, const int colCount);
int negcol(int** a, const int rowCount, const int colCount);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -2;
	int High = 10;
	int n, k;
	cout << "rowCount = "; cin >> n;//rowCount
	cout << "colCount = "; cin >> k;//colCount
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	//Create(a, n, k, Low, High);
	Input(a, n, k);
	Print(a, n, k);
	negcol(a, n, k);
	Sort(a, n,k);
	Print(a, n, k);
	
	
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
int  rows, cols;
for (rows = 0; rows < rowCount; rows++)
	sort(a[rows], a[rows] + colCount);
}
int negcol(int** a, const int rowCount, const int colCount)
{
	int foundColumn = 0;
	bool flag;
	for (int i = 0; i < colCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			if (a[j][i] >= 0) {
				flag = true;
				continue;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			foundColumn = i + 1;
	}
	if (foundColumn)
		cout << "Column number " << foundColumn << " hasn't any negative numbers.\n";
	else
		cout << "All columns contains negative numbers.\n";
	return 0;
}