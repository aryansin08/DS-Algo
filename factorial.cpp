#include<bits/stdc++.h>
using namespace std;
int fac(int n)	{
	if(n==0 || n==1)
		return 1;
	else 
		return fac(n-1)*n;
}

int main()	{
	int n, fact;
	cout<<"Enter the number : ";
	cin>>n;
	fact=fac(n);
	cout<<"The factorial of "<<n<<" is "<<fact;
	return 0;
	
}
