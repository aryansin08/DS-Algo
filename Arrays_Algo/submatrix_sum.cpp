#include<bits/stdc++.h>
using namespace std;	

int main()	{
	int a[10][10];
	int m, n, sum=0;
	cin>>m>>n;
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	
			cin>>a[i][j];
	}
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	{
			sum+=a[i][j]*(i+1)*(j+1)*(m-i)*(n-j);
		}
	}
	cout<<sum;

}
