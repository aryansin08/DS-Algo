#include<bits/stdc++.h>
using namespace std;
int fun(int n)	{
	cout<<n<<endl;
	if(n>100)
		return n-10;
	else
		return fun(fun(n+11));
}

int main()	{
	int n;
	cin>>n;
	fun(n);
	return 0;
}
