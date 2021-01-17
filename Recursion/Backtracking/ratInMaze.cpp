#include<bits/stdc++.h>

using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)	{
	if(i==m and j==n)	{
		soln[m][n] = 1;
		//Print the path
		cout<<"Path is : "<<endl;
		for(int i=0;i<=m;i++)	{
			for(int j=0;j<=n;j++)	{
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	//Rat should always be inside the grid
	if(i>m or j>n)	{
		return false;
	}
	if(maze[i][j]=='X')
		return false;
	//Assume soln exists through current cell
	soln[i][j]=1;

	//Recursive Case
	bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n );
	bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

	//Backtracking
	soln[i][j] = 0;

	if(rightSuccess or downSuccess)	{
		return true;
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
    	char maze[10][10] = {"0000",
    						 "00X0",
    						 "000X",		
							 "0X00"};
		int soln[10][10]={0};
		int m = 4, n = 4;
		bool ans = ratInMaze(maze, soln, 0, 0, m-1, n-1);

		if(ans==false)	{
			cout<<"Path does not exist";
		}
		return 0;
}