#include<bits/stdc++.h>	
using namespace std;
int sum(int n)	{
	if(n==1)
		return 1;
	else
		return sum(n-1) + n;
}

int main()	{
	int n;
	cin>>n;
	int s=sum(n);
	cout<<"The sum of the first "<<n<<" natural numbers is "<<s;
	return 0;
}
