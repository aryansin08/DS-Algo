#include<bits/stdc++.h>

using namespace std;

bool isSorted(int *a, int n)	{
	if(n==0 || n==1)
		return true;
	if(a[0]<a[1] && isSorted(a+1, n-1))
		return true;
	return false;
}

int main()	{
	int a[]= {1, 3, 5, 7, 9};
	cout<<isSorted(a, 5);
	return 0;
}
