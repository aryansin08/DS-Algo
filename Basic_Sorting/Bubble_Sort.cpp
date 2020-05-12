#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)	{
	for (int i=0;i<n-1;i++)	{
		for(int j=0;j<n-i-1;j++)	{
			if(a[j]>a[j+1])	{
				swap(a[j], a[j+1]);
			}
		}
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
	bubble_sort(a, n);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
}
