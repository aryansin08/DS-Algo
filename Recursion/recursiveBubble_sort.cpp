#include<bits/stdc++.h>

using namespace std;
//one variable to handle outer loop and one two handle inner loop
void recursiveBubble_sort(int a[], int j, int n)	{
	//Base Case
	if(n==1)	{
		return;
	}
	if(j==n-1)	{
		//outer loop
		return recursiveBubble_sort(a, 0, n-1);
	}
	if(a[j]>a[j+1])	{
		swap(a[j], a[j+1]);
	}
	//inner loop
	recursiveBubble_sort(a, j+1, n);
	return;
}

int main()	{
	int a[] = {5, 4, 3, 1};
	for(int i=0;i<4;i++)	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	recursiveBubble_sort(a, 0, 4);
	for(int i=0;i<4;i++)	{
		cout<<a[i]<<" ";
	}
	return 0;
}
