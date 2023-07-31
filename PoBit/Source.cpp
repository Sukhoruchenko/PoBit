#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;

typedef unsigned char UC;

void RandMas(int *a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}

void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int OprBit(int *a, int n)
{
	int Max = a[0], k = 31;
	for (int i = 0; i < n; i++)
		if (a[i] > Max)	Max = a[i];
	int  mask = 1 << 31;
	while (Max&mask==0) 
	{		
		k--;
		mask >>= 1;
	}
	return k;
}

void SortPoBit(int *a, int l, int r, int k)
{
	if (l >= r || k < 0) return;
	else
	{
		int i = l, j = r, mask = 1 << k;
		while (i <= j)
		{
			while ((i <= j) && (((a[i] & mask) == 0))) i++;
			while ((i <= j) && (((a[j] & mask) != 0))) j--;
			if (i < j)
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		if (l < j) SortPoBit(a, l, j, k - 1);
		if (i < r) SortPoBit(a, i, r, k - 1);
	}

}

void main()
{
	int  *a, n, i, k;// k-номер старшего разряда
	cout << "input kol-vo elements: ";
	cin >> n;
	a = new int[n];
	RandMas(a, n);
	Output(a, n);
	k = OprBit(a, n);
	SortPoBit(a, 0, n - 1, k);
	Output(a, n);
	delete[] a;
	_getch();
}
