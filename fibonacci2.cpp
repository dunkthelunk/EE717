#include<iostream>
using namespace std;
long long int fib(int);

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	cout << "F(" << n << ") = " << fib(n) << endl;
}

long long int fib(int n)
{
	long long int a1=1,a2=1;
	for (int i=3; i<=n; i++)
	{
		int temp = a2;
		a2 = a1 + a2;
		a1 = temp;
	}
	return a2;
}
