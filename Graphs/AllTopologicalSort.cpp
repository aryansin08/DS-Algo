#include<bits/stdc++.h>
using namespace std;

void sort(vector<vector<int>> &adj, vector<int> &indegree, vector<int> &vis, vector<vector<int>> &ans, vector<int> &temp, int n)	{
	
	if(temp.size()==n)	{
		ans.push_back(temp);
		return;
	}

	for(int i=0;i<n;++i)	{

		if(!indegree[i] and !vis[i])	{

			temp.push_back(i);
			for(auto &nbr : adj[i])	{
				indegree[nbr]--;
			}
			vis[i] = 1;

			sort(adj, indegree, vis, ans, temp, n);

			temp.pop_back();
			for(auto &nbr : adj[i])	{
				indegree[nbr]++;
			}
			vis[i] = 0;
		}
	}
}

vector<vector<int>>	printAllTopologicalSorts(vector<vector<int>> adj, int n)	{

	vector<int> indegree(n);

	for(int i=0;i<n;++i)	{
		for(auto x : adj[i])	{
			indegree[x]++;
		}
	}

	vector<int> vis(n);
	vector<vector<int>> ans;
	vector<int> temp;
	sort(adj, indegree, vis, ans, temp, n);
	return ans;
}

int main()	{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> adj(6);
    adj[5] = vector<int>{2, 0};
    adj[4] = vector<int>{0, 1};
    adj[2].push_back({3});
    adj[3].push_back({1});
    vector<vector<int>> ans = printAllTopologicalSorts(adj, 6);
    for(auto v : ans)	{
    	for(auto x : v)	cout<<x<<" ";
    	cout<<endl;
    }
    return 0;
}





