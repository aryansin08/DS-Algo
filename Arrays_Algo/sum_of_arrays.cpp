#include<bits/stdc++.h>
using namespace std;

int main() {
	int m;
	cin>>m;
	int i;
	int a[1000];
	for(i=0;i<m;i++)
		cin>>a[i];
	int n;
	cin>>n;
	int b[1000];
	for(i=0;i<n;i++)
		cin>>b[i];
		
	int amax = max(m, n);
	int k=amax;
	int amin = min(m, n);
	int sum[1001];	
	if(m!=n)	{
	if(amax==m)	{
		for(i=0;i<m-n;i++)
			sum[i] = a[i];
	}
	else	{
		for(i=0;i<n-m;i++)
			sum[i] = b[i];
	}
	}
	int s=0, c=0, g=0;
	while(amin>0)	{
		s = c + a[--m] + b[--n];
		c = s/10;
		sum[--amax] = s%10;
		amin--; 
	}
	for(i=0;i<k;i++)
		cout<<sum[i]<<", ";
	cout<<"END";
	
	return 0;
}
