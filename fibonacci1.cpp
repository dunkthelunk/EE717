#include<iostream>
using namespace std;
long long int fib(int);

int main() 
{
	int n;
	cout << "n = ";
	cin >> n;
	cout << "F("<< n << ") = " << fib(n) << endl;
}

long long int fib(int n) 
{
	if (n <= 2) return 1;
	else return fib(n-1)+fib(n-2);
}
