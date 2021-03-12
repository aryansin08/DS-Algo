#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> &board, int i, int j, int n)	{
	for(int row = 0;row<i;++row)	{
		if(board[row][j]==1)	return false;
	}
	int x = i, y = j;
	while(x>=0 and y>=0)	{
		if(board[x--][y--]==1)	return false;
	}
	x = i, y = j;
	while(x>=0 and y<n)	{
		if(board[x--][y++]==1)	return false;
	}
	return true;
}

bool nQueen(vector<vector<int>> &board, int n, int i)	{
	if(i==n)	{
		for(auto &v : board)	{
			for(auto &x : v)	cout<<x<<" ";
			cout<<endl;
		}
		return true;
	}
	for(int j=0;j<n;++j)	{
		if(isSafe(board, i, j, n))	{
			board[i][j] = 1;

			if(nQueen(board, n, i+1))	return true;

			//Backtracking
			board[i][j] = 0;
		}
	}
	return false;
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<vector<int>> board(n, vector<int>(n));
	nQueen(board, n, 0);
	return 0;	
}