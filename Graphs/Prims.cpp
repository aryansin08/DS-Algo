#include<bits/stdc++.h>

using namespace std;

class Graph	{
	//Adjacency list implementation
	vector<pair<int, int>> *l;
	int V;

public:
	Graph(int n)	{
		V = n;
		l = new vector<pair<int, int>>[n];
	}

	void addEdge(int x, int y, int w)	{
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst()	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

		//To check wether node has been added to the MST
		bool *visited = new bool[V]{0};
		int ans = 0;

		Q.push({0, 0}); //{weight, node}

		while(!Q.empty())	{
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(!visited[to])	{
				ans += weight;
				visited[to]=1;

				for(auto &x : l[to])	{
					if(!visited[x.first])	{
						Q.push({x.second, x.first});
					}
				}
			}
		}
		return ans;
	}
};

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

    int n, e;
    cin>>n>>e;

    Graph g(n);

    for(int i=0;i<e;++i)	{
    	int w, u, v;
    	cin>>u>>v>>w;
    	g.addEdge(u-1, v-1, w);
    }

    cout<<g.prim_mst();
	
}