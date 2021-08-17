#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> solve(vector<vector<string>> &mat)	{
	int max_fall = INT_MAX;
	for(int j = 0;j<mat[0].size();++j)	{
        int last_f = INT_MAX;
		for(int i = 0;i<mat.size();++i)	{
			if(mat[i][j]=="F")  last_f = i;
			else if(mat[i][j]=="#")	max_fall = min(max_fall, abs(i-last_f-1));
	    }
    }
    vector<vector<string>> temp(mat);
	for(int j = 0;j<mat[0].size();++j)	{
		for(int i = 0;i<mat.size();++i)	{
			if(temp[i][j]=="F")   {
                int d = i;
                while(d+max_fall<mat.size() and temp[d+max_fall][j]=="F")  {
                    d+=max_fall;
                }
                if(d+max_fall<mat.size())
                    swap(mat[i][j], mat[d+max_fall][j]);
            }
		}
	}
	return mat;
}
 
int main() {
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	vector<vector<string>> matrix {
        {"F", "F", "F"},
		{".", "F", "."},
		{".", "F", "F"},
		{"#", "F", "."},
		{"F", "F", "."},
		{".", ".", "."},
		{".", ".", "#"},
		{".", ".", "."}
    };
	solve(matrix);
	for(auto v : matrix)	{
		for(auto x : v)	cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}