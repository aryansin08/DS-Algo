#include<bits/stdc++.h>
using namespace std;

//Pair Sum

int pair_sum(int a[], int n,int key)	{
	int i=0, j = n-1;
	while(i<j)	{
		int sum = a[i] + a[j];
		if(sum<key)
			i++;
		else if(sum>key)
			j--;
		else	{
			cout<<a[i]<<" and "<<a[j]<<endl;
			i++;
			j--;
		}
	}
}

int main()	{
	int a[] = {1, 2, 3, 4, 7, 9, 10, 12, 14, 15};
	int n = sizeof(a)/sizeof(a[0]);
	pair_sum(a, n, 16);
	
}
