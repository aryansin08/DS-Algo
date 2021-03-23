#include<bits/stdc++.h>

using namespace std;
template<typename T>
class Graph	{

	map<T, list<T>> l;

public:

	void addEdge(T x, T y)	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited)	{
		if(visited[src])	return;
		visited[src]=true;
		cout<<src<<" ";
		for(auto &x: l[src])	{
			if(!visited[x])	{
				dfs_helper(x, visited);
			}
		}
	}

	void dfs(T src)	{
		map<T, bool> visited;
		dfs_helper(src, visited);
	}

};
int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	Graph<int> g;
    	g.addEdge(0,1);
    	g.addEdge(1,2);
    	g.addEdge(2,3);
    	g.addEdge(3,4);
    	g.addEdge(4,5);
    	g.addEdge(3,0);
    	g.dfs(0);
	
}