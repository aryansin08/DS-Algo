#include<bits/stdc++.h>

using namespace std;

void waveSort(vector<int> &v)	{
	int n = v.size();
	if(n==1 or n==0)	return;
	int i=0;
	while(i<n)	{
		if(i!=0 and v[i]<v[i-1])	swap(v[i], v[i-1]);
		if(i!=n-1 and v[i]<v[i+1])	swap(v[i], v[i+1]);
		i+=2;	
	}
	return;
}
int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	vector<int> v({1,3,4,7,2,4});
    waveSort(v);
    for(int &x:v)	cout<<x<<" ";
	return 0;
}