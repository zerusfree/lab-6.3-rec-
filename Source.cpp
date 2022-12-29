#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
template < typename A >
void Create(A* a, A size, A Low, A High, A i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
template < typename A >
void Print(A* a, A size, A i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}
template < typename A >
A Sum(A* a, A size, A i,int S)
{
	S += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, S);
	else
		return S;
}

int main()
{
	srand((unsigned)time(NULL));
	int n, Low, High;

	cout << "n = ";	cin >> n;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;

	int* a = new int[n];

	Create(a, n, Low, High, 0);
	cout << "a [";
	Print(a, n, 0);
	cout << " ]" << endl;

	cout << "S = " << Sum(a, n, 0,0) << endl;
	delete[] a;
	return 0;
}
