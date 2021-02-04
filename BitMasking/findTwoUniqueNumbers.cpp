#include<bits/stdc++.h>

using namespace std;
//Find two unique numbers in the given array;

vector<int> uniqueNumbers(int arr[], int n)	{
	int x = 0;
	for(int i=0;i<n;i++)	{
		x^=arr[i];
	}
	cout<<x<<endl;
	int pos = 0;
	int temp = x;
	while((temp&1)!=1)	{
		++pos;
		temp = temp>>1;
	}
	cout<<pos<<endl;
	int a=0;
	int mask = 1<<pos;
	for(int i=0;i<n;i++)	{
		if((mask & arr[i])>0)	{
			a^=arr[i];
		}
	}
	return {a, a^x};
}

int main()	{
	int arr[] = {5, 1, 2, 2, 3, 1, 5, 7};
	vector<int> v(uniqueNumbers(arr, 8));
	cout<<v[0]<<" "<<v[1];
	return 0;
}