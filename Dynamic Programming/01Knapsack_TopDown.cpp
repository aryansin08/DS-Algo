#include<bits/stdc++.h>

using namespace std;

int static t[100][1000];

int knapsack(int val[], int wt[], int n, int W)	{
	for (int i = 1; i <= n; i++)	{
		for (int j = 1; j <= W; j++)	{
			if (wt[i - 1] <= j)	{
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i-1]], t[i - 1][j]);
			}
			else	{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][W];


}

int main()	{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, W;
	cin >> n >> W;
	int weight[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};
	memset(t, -1, sizeof(t));
	for (int i = 0; i < n + 1; i++)	{
		for (int j = 0; j < W + 1; j++)	{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	cout <<"Maximum Profit : " << knapsack(prices, weight, n, W)<<endl;

	for (int i = 0; i < n + 1; i++)	{
		for (int j = 0; j < W + 1; j++)	{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}
