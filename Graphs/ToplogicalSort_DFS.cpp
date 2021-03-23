#include<bits/stdc++.h>

using namespace std;
template<typename T>
class Graph	{

	map<T, list<T>> l;

public:

	void addEdge(T x, T y)	{
		l[x].push_back(y);
	}

	void dfs_helper(T node, map<T, bool> &visited, list<T> &ordering)	{
		if(visited[node])	return;
		visited[node]=true;
		for(auto &x: l[node])	{
			if(!visited[x])	{
				dfs_helper(x, visited, ordering);
			}
		}
		ordering.push_front(node);
	}

	list<T> dfs()	{
		map<T, bool> visited;
		list<T> ordering;
		for(auto p : l)	{
			T node = p.first;
			if(!visited[node])
				dfs_helper(node, visited, ordering);
		}
		return ordering;
	}

};
int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	Graph<string> g;
    	g.addEdge("Python","DataPreprocessing");
    	g.addEdge("Python","PyTorch");
    	g.addEdge("Python","ML");
    	g.addEdge("ML","DeepLearning");
    	g.addEdge("DeepLearning","FaceRecognition");
    	g.addEdge("DataSet","FaceRecognition");
    	list<string> t = g.dfs();
    	for(auto x:t)	cout<<x<<endl;
	return 0;
}