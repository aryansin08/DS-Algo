#include<bits/stdc++.h>

using namespace std;

//Print all subsets of a string using bitwise operators

void filterChars(string str, int n)	{
	int j = 0;
	while(n)	{
		int lsb = n&1;
		if(lsb)	
			cout<<str[j];
		n = n>>1;
		j++;
	}
	cout<<" ";
}

void printSubsets(string str, int n)	{
	for(int i=0;i<(1<<n);i++)	{
		filterChars(str, i);
	}
	return;
}

int main()	{
	string s;
	cout<<"Enter String : ";
	cin>>s;
	printSubsets(s, s.length());
	return 0;
}