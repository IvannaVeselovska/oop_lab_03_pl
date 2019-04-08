#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L=new int[n1], *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main() {
	printf("\ninput current date");
	int d1, m1, y1;
	scanf("\n%d%d%d", &d1, &m1, &y1);
	Date now = new Date(d1, m1, y1);
	printf("input number of dates");
	int n;
	scanf("%d", &n);
	Date *a=new Date[n];
	for (int i = 0; i < n; i++)
	{
		int d, m, y;
		printf("\ninput your date");
		scanf("\n%d%d%d", &d, &m, &y);
		a[i] = new Date(d, m, y);
	}

	Date g(a[0]);
	g.Increase();
	g.Module(now);
	printf("\n day - %d", g.GetDay());
	printf("\n month - %d", g.GetMonth());
	printf("\n year - %d", g.GetYear());
	delete a;
	system("pause");
}
