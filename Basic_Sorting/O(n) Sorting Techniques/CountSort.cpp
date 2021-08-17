#include<bits/stdc++.h>

using namespace std;

void CountSort(int [], int);

int main()	{
	int a[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
	cout<<"Unsorted Array\n";
	for(int i=0;i<10;i++)	{
		cout<<a[i]<<" ";
	}
	CountSort(a, 10);
	cout<<"\n\nSorted Array\n";
	for(int i=0;i<10;i++)	{
		cout<<a[i]<<" ";
	}
}

void CountSort(int a[], int n)	{
	int max;
	int *count;

	max = a[0];
	for(int i=1;i<n;i++)	{
		if(a[i]>max)
			max = a[i];
	}

	count = new int[max+1]{0};

	// for(int i=0;i<=max;i++)	{
	// 	count[i] = 0;
	// }

	for(int i=0;i<n;i++)	{
	++count[a[i]];
	}

	int i=0, j=0;
	while(i<max+1)	{
		if(count[i]>0)	{
			a[j++] = i;
			count[i]--;
		}
		else	{
			i++;
		}
	}
	return;
}