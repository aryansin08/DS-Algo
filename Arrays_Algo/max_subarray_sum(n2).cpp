#include<bits/stdc++.h>
using namespace std;

int main()	{
	int i, j, max = INT_MIN, r, l;
	int a[] = {-4, 1, 3, -2, 6, 2, -8, -9, 4};
	int n = sizeof(a)/sizeof(a[0]);
	int cumSum[n] = {0};
	cumSum[0] = a[0];
	cout<<"Array : ";
	for(i = 0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<cumSum[0]<<" ";
	for(i = 1 ; i<n ; i++)	{
		cumSum[i] = cumSum[i-1] + a[i];
		cout<<cumSum[i]<<" ";
	}
	for(i=0;i<n;i++)	{
		for(j=i;j<n;j++)	{
			int sum = 0;
			sum = cumSum[j] - cumSum[i-1];
			if(sum>max)	{
				max=sum;
				l = i;
				r = j;
			}
		}
	}
	cout<<endl;
	cout<<"Maximum Subarray : ";
	for(i=l;i<=r;i++)	
		cout<<a[i]<<" ";
	cout<<endl<<"Maximum Sum : "<<max;
}
