#include<iostream>
using namespace std;

int main()
{
	int n = 6;
	int array[n];
	
	for (int i=0; i < n; i++)
	{
		cin >> array[i];
	}
	
	for (int j = 1; j < n; j++)
	{
		int temp = array[j];
		int k = j-1;
		while (temp < array[k])
		{
			array[k+1] = array[k];
			k--;	
		}
		array[k+1] = temp;	
	}
	
	for (int i=0; i<n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;	
}
