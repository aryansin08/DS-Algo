#include<bits/stdc++.h>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

	int primes[10000001] = {0};
	for(long long i=3;i<=10000000;i+=2)	{
		primes[i] = 1;
	}
	for(long long i=3;i<=10000000;i+=2)	{
		if(primes[i])	{
			for(long long j = i*i;j<=10000000;j+=i)	{
				primes[j] = 0;
			}
		}
	}
	primes[2] = 1;
	int cnt[10000001];
	memset(cnt, 10000000, sizeof(cnt));
	cnt[0] = 0;
	for(long long i=1;i<10000000;++i)	{
		primes[i]+=primes[i-1];
		// cout<<i<<" "<<primes[i]<<endl;
		cnt[primes[i]] = min((long long)cnt[primes[i]], i);
		// cout<<i<<" "<<cnt[primes[i]]<<endl;
	}
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		cout<<cnt[n]<<endl;
	}
	return 0;
}