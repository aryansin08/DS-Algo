#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b)	{
	return a<=b;
}

int main()	{
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int money;
	cout<<"Enter amount : ";
	cin>>money;
	cout<<endl;
	int n = sizeof(coins)/sizeof(coins[0]);
	while(money>0)	{
		int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
		cout<<" "<<coins[lb];
		money-=coins[lb];
	}
	cout<<endl;
}