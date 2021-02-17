#include<bits/stdc++.h>

using namespace std;

void printFactors(int n)	{
	vector<pair<int, int>> factors;
	for(int i=2;i*i<=n;++i)	{
		if(n%i==0)	{
			int count_i=0;
			while(n%i==0)	{
				n/=i;
				++count_i;
			}
			factors.push_back({i, count_i});
	}
	}
	if(n!=1)	factors.push_back({n, 1});
	for(int i=0;i<factors.size();++i)	{
		for(int j=0;j<factors[i].second;++j)	{
			cout<<factors[i].first<<" ";
		}
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
   	int n;
   	cin>>n;
	printFactors(n);
	return 0;
}