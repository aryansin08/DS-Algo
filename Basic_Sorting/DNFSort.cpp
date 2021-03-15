#include<bits/stdc++.h>

using namespace std;
void sort(vector<int> &v)	{
	int l = 0, m = 0, r = v.size()-1;
	while(m<=r)	{
		if(v[m]==0)	swap(v[m++], v[l++]);
		else if(v[m]==2)	swap(v[m], v[r--]);
		else	++m;
	}
}
int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
   	vector<int> v({0,1,1,0,1,2,1,0,0,2,1});
    sort(v);
    for(int &x:v)	cout<<x<<" ";
	return 0;
}