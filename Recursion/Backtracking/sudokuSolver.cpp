#include<bits/stdc++.h>

using namespace std;

bool canPlace(vector<vector<int>> &matrix, int i, int j, int val)	{
	for(int x=0;x<9;++x)	{
		if(matrix[x][j]==val or matrix[j][x]==val)	return false;
	}
	int sx = (i/3)*3;
	int sy = (j/3)*3;
	for(int x=sx;x<sx+3;++x)	{
		for(int y=sy;y<sy+3;++y)	{
			if(matrix[x][y]==val)	return false;
		}
	}
	return true;
}

bool solve(vector<vector<int>> &matrix, int i, int j)	{
	if(i==n)	return true;
	if(j==9)	return solve(matrix, i+1, 0);
	if(matrix[i][j]!=0)	return solve(matrix, i, j+1);
	for(int num=1;num<=9;++num)	{
		if(canPlace(matrix, i, j, num))	{
			matrix[i][j]=num;
			if(solve(matrix, i, j+1))	return true;
		}
	}
	matrix[i][j]=0;
	return false;
}


int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	
}