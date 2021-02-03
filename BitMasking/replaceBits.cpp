#include<bits/stdc++.h>

//replace bit of n ranging from i(LSB) to j(MSB) with m 
using namespace std;
int clearBits(int n,int i,int j)	{
	int ones = ~0;
	int a = ones<<(j+1);
	int b = (1<<i)-1;
	int mask = a | b;
	return mask & n;
}

int replaceBits(int n, int m, int i, int j)	{
	m = m<<i;
	n = clearBits(n, i, j);
	return m | n;
}

int main()	{
	cout<<replaceBits(15, 2, 1, 3);
	return 0;
}