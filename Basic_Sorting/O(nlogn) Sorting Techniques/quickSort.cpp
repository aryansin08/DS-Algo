#include<iostream>

using namespace std;

int partition(int *a, int s, int e)	{
	int i=s-1; //iterates over the smaller element partition
	int j=s; //iterates over the larger element partition
	int pivot = a[e];
	
	for(;j<=e-1;)	{
		if(a[j]<=pivot)	{
			//increase the size of the smaller partition to move a[j] to index i+1
			i++;
			swap(a[i], a[j]);
		}
		//expand the larger region
		j++;
	}
	swap(a[e], a[i+1]);
	return i+1;
}

void quickSort(int *a, int s, int e)	{
	if(s>=e)
		return;
	int p = partition(a, s, e);
	quickSort(a, s, p-1);
	quickSort(a, p+1, e);
}

int main()	{
	int a[] = {5, 4, 7, 2, 8, 9, 11, 3};
	for(int i=0;i<8;i++)	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	quickSort(a, 0, 7);
	
	for(int i=0;i<8;i++)	{
		cout<<a[i]<<" ";
	}
}

