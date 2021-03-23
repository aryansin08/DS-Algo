#include<bits/stdc++.h>

using namespace std;


class Graph	{
	map<int, list<int>> l;
public:

	void addEdge(int x, int y)	{
		l[x].push_back(y);
	}

	void topological_sort()	{
		//Calculating indegree of all nodes
		vector<int> indegree(l.size());
		for(auto p:l)	{
			for(auto y:p.second)	{
				indegree[y]++;
			}
		}

		//BFS
		queue<int> q;
		for(int i=0;i<l.size();++i)	{
			if(indegree[i]==0)	{
			//Pushin node to queue if it is not dependent on anyone i.e indegree=0
				q.push(i);
			}
		}

		while(!q.empty())	{
			int node = q.front();
			//Prints elements topologically sorted
			cout<<node<<" ";
			q.pop();
			for(auto nbr:l[node])	{
				indegree[nbr]--;
				if(!indegree[nbr])	q.push(nbr);
			}		
		}
	}
};

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	Graph g;    	
    	g.addEdge(0,1);
    	g.addEdge(1,2);
    	g.addEdge(2,3);
    	g.addEdge(3,4);
    	g.addEdge(4,5);
    	g.topological_sort();
    	return 0;
	
}