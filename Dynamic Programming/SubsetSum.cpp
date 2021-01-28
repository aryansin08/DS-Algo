#include<bits/stdc++.h>

using namespace std;

//Return true of there exists a subset whose sum is the target sum

vector<vector<bool>> dp(5, vector<bool>(12, false));

bool subsetSum(vector<int> arr, int sum)	{
	for(int i=1;i<dp.size();i++)	{
		for(int j=1;j<dp[0].size();j++)	{
			if(arr[i-1]<=j)	{
				dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[dp.size()-1][dp[0].size()-1];
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

    for(int i=0;i<dp.size();i++)	{
    	for(int j=0;j<dp[0].size();j++)	{
    		if(i==0)
    			dp[i][j]=false;
    		if(j==0)
    			dp[i][j] = true;
    	}
    }
    vector<int> arr{2, 3, 8, 10};
    int sum = 11;
    cout<<subsetSum(arr, sum);
    return 0;
}