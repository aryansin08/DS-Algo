#include<bits/stdc++.h>

using namespace std;
//All numbers are present k times in an array except one.We need to find that num;
int findUnique(int arr[], int n, int k)	{
	int bits[64] = {0};
	for(int i=0;i<n;++i)	{
		int index = 0;
		while(arr[i])	{
			bits[index++]+=arr[i]&1;
			arr[i] = arr[i]>>1;
		}
	}
	int p = 0;
	int ans = 0;
	for(int i=0;i<64;i++)	{
		if(bits[i]%k==1)
			ans+=pow(2,p);
		++p;
	}
	return ans;
}
int main()	{
	int arr[] = {19, 19, 19, 3, 3, 3, 87, 7, 7, 7, 14, 14, 14};
	cout<<findUnique(arr, sizeof(arr)/sizeof(arr[0]), 3);
	return 0;
}