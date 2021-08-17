#include<bits/stdc++.h>
using namespace std;
void calculate(vector<vector<int>> &adj, int *dist, int &src, int *vis)	{
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	int k = 6;
	while(!q.empty())	{
		int n = q.size();
		for(int i=0;i<n;++i)	{
			int src = q.front();
			q.pop();
			for(auto &nbr : adj[src])	{
				if(!vis[nbr])	{
					// cout<<src<<" "<<nbr<<endl;
					q.push(nbr);
					vis[nbr] = 1;
					dist[nbr] = k;
				}
			}
		}
		k+=6;
	}

}
int main() {
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--)	{
		int n, m;
		cin>>n>>m;
		int dist[n+1];
		memset(dist, -1, sizeof(dist));
		vector<vector<int>> adj(n+1);
		for(int i=0;i<m;++i)	{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int src;
		cin>>src;
		int vis[n+1] = {0};
		calculate(adj, dist, src, vis);
		for(int i=1;i<=n;++i)	{
			if(i!=src)	cout<<dist[i]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}