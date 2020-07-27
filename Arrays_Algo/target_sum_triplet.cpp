#include<iostream>
using namespace std;
#include<algorithm>
int main() {
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int t;
	cin>>t;
	sort(a, a+n);
	int i=0, l=1, r=n-1;
	while(i<n)	{
		while(l<r)	{
			if(a[i]+a[l]+a[r]==t)	{
				cout<<a[i]<<", "<<a[l]<<" and "<<a[r]<<endl;
				l++;
				r--;
			}
			else if(a[i]+a[l]+a[r]<t)	l++;
			else r--;
		}
		i++;
		l=i+1;
		r=n-1;
	}
	return 0;
}