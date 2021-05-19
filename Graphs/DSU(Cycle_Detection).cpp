#include<bits/stdc++.h>

using namespace std;

class Graph	{
	int V;
	list<pair<int, int>> l;

public:
	Graph(int V)	{
		this->V = V;
	}

	void addEdge(int u, int v)	{
		l.push_back({u, v});
	}

	int findSet(int i, vector<int> &parent)	{
		if(parent[i]==-1)	return i;
		return parent[i] = findSet(parent[i], parent);
	}

	bool union_set(int x, int y, vector<int> &parent, vector<int> &rank)	{
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);
		if(s1!=s2)	{
			if(rank[s1]>rank[s2])	{
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}
			else	{
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			}
			return false;
		}
		return true;	
	}

	bool contains_cycle()	{
		vector<int> parent(V, -1);
		vector<int> rank(V, 1);
		for(auto &edge : l)	{
			int i=edge.first;
			int j = edge.second;
			bool cycle = union_set(i, j, parent, rank);
			if(cycle)	return true;
		}
		return false;
	}


};

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	Graph g(4);
    	g.addEdge(0, 1);
    	g.addEdge(1, 2);
    	g.addEdge(2, 3);
    	// g.addEdge(3, 0);
    	cout<<g.contains_cycle();
	
}