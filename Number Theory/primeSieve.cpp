#include<bits/stdc++.h>

using namespace std;

void primeSieve(int *prime)	{
	for(int i=3;i<=1000000;i+=2)	
        prime[i] = 1;
	for(long long i=3;i<=1000000;i+=2)	{
		if(prime[i])	{
			for(long long j=i*i;j<1000000;j+=i)	{
				prime[j] = 0;
			}
		}
	}
	prime[2] = 1;
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
	int prime[1000000] = {0};
	primeSieve(prime);
	for(int i=0;i<=n;++i)   {
		if(prime[i])
			cout<<i<<" ";
    }
	return 0;
}
