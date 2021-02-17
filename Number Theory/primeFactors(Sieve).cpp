#include<bits/stdc++.h>

using namespace std;

vector<int> prime;
//Creating Sieve
void sieve()	{
	vector<int> p(100000, 0);
	for(int i=3;i<100000;i+=2)	{
		p[i]=1;
	}
	for(long long i=3;i<100000;i+=2)	{
		if(p[i])	{
			for(long long j=i*i;j<100000;j+=i)
				p[j] = 0;
		}
	}
	prime.push_back(2);
	for(int i=3;i<p.size();i+=2)	{
		if(p[i])
			prime.push_back(i);
	}
}

void factorize(int n)	{
	vector<pair<int, int>> factors;
	int i=0;
	int p = prime[i];
	//Dividing by prime numbers
	while(p*p<=n)	{
		if(n%p==0)	{
			int count=0;
			while(n%p==0)	{
				++count;
				n/=p;
			}
			factors.push_back({p, count});
		}
		++i;
		p = prime[i];
	}
	if(n!=1)	factors.push_back({n, 1});

	//Printing the factors
	for(int i=0;i<factors.size();++i)	{
		for(int j=0;j<factors[i].second;++j)	{
			cout<<factors[i].first<<" ";
		}
	}
}


int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    sieve();
    int n;
    cin>>n;
    factorize(n);
	return 0;
}