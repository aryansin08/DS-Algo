#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(6, vector<int>(11));

//Count the number of subsets of an array whose sum is equal to the target sum

int countSubsetSum(vector<int> arr, int sum)	{
	for(int i=1;i<dp.size();i++)	{
		for(int j=1;j<dp[0].size();j++)	{
			if(arr[i-1]<=j)	{
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
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
    			dp[i][j]=0;
    		if(j==0)
    			dp[i][j] = 1;
    	}
    }
    vector<int> arr{2, 3, 5, 8, 10};
    int sum = 10;
    cout<<countSubsetSum(arr, sum)<<endl<<"DP Matrix"<<endl;
    for(int i=0;i<dp.size();i++)    {
        for(int j=0;j<dp[0].size();j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}