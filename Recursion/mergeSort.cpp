#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &a, int start, int end)	{
	int mid = start + (end - start)/2;
	int i = start, j = mid+1;
	vector<int> temp;
	while(i<=mid and j<=end)	{
		if(a[i]<=a[j])	temp.push_back(a[i++]);
		else	temp.push_back(a[j++]);
	}
	while(i<=mid)	temp.push_back(a[i++]);
	while(j<=end)	temp.push_back(a[j++]);
	int k = 0;
	for(int i = start; i<=end; ++i)	{
		a[i] = temp[k++];
	}
	return;
}
void MergeSort(vector<int> &a, int start, int end)	{
	if(start>=end)	return;
	int mid = start + (end - start)/2;
	MergeSort(a, start, mid);
	MergeSort(a, mid+1, end);
	Merge(a, start, end);
	return;
}
int main() {
	int n;
	cin>>n;
	vector<int> a;
	int temp = n;
	while(temp--)	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	MergeSort(a, 0, n-1);
	for(auto &x: a)	cout<<x<<" ";
	return 0;
}
