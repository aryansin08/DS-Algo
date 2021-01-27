#include<bits/stdc++.h>
using namespace std;
//Kadane's Algo
int kadane(int a[], int n)	{
	int maxSum = INT_MIN, cumSum = 0;
	for(int i=0;i<n;i++)	{
		cumSum = cumSum+a[i];
		maxSum = max(maxSum, cumSum);
		if(cumSum<0)
			cumSum = 0;
	}
	return maxSum;
}

int main()	{
	int a[] = {-4, 1, 3, -2, 6, 2, -8, -9, 4};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"For array : ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;	
	cout<<"Max Subarray Sum is : "<<kadane(a, n);
}
