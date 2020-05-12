#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)	{
	int temp;
	for(int i=0;i<n-1;i++)	{
		int min_index = i;
		for(int j=i;j<n;j++)	{
			if(a[j]<a[min_index])	{
				min_index=j;
			}
		}
		/*
		temp=a[i];
		a[i]=a[min_index];
		a[min_index]=temp;
		*/
		swap(a[i], a[min_index]);
	}
}

int main()	{
	int n, a[100];
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	cout<<"Unsorted array"<<endl;
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	selection_sort(a, n);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
}
