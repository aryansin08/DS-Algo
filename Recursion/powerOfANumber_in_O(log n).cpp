#include<bits/stdc++.h>

using namespace std;

int fast_power(int a, int n)	{
	if(n==0)
		return 1;
	if(n&1)
		return a*pow(fast_power(a, n/2), 2);
	return pow(fast_power(a, n/2), 2);
}

int main()	{
	cout<<fast_power(4, 5);
	return 0;
}
