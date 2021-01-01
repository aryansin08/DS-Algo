//Memoization - Top Down

#include<bits/stdc++.h>

using namespace std;

int static t[100][1000];

int recursive_knapsack(int wt[], int val[], int W, int n)	{

	//Base Case
	if(n==0 || W==0)	{
		return 0;
	}

	if(t[n][W]!=-1)
		return t[n][W];

	//Recursive Case
	if(wt[n-1]<=W)
		return t[n][W] = max(val[n-1] + recursive_knapsack(wt, val, W-wt[n-1], n-1), recursive_knapsack(wt, val, W, n-1));

	else
		return t[n][W] = recursive_knapsack(wt, val, W, n-1);

}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

	memset(t, -1, sizeof(t));

    int weight[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	cout<<recursive_knapsack(weight, prices, 7, 4)<<endl;
    return 0;

	
}
