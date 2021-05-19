#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph	{

	unordered_map<T, list<pair<T, int>>> m;

public:
	void addEdge(T u, T v, int dist, bool bidir=true)	{
		m[u].push_back(make_pair(v, dist));
		if(bidir)	{
			m[v].push_back(make_pair(u, dist));
		} 
	}

	void printAdj()	{
		for(auto &j : m)	{
			cout<<j.first<<"->";

			for(auto &l : j.second)	{
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void dijkstraSSSP(T src)	{
		unordered_map<T, int> dist;
		//set all distances to inf
		for(auto node : m)	{
			dist[node.first] = INT_MAX;
		}
		//set to find node with min distance
		set<pair<int, T>> s;

		dist[src] = 0;
		s.insert({0, src});

		while(!s.empty())	{
			//find the pair at the front
			auto p = *s.begin();
			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());

			//Iterate over neighbours of the current node
			for(auto childPair : m[node])	{
				if(nodeDist + childPair.second<dist[childPair.first])	{
					T dest = childPair.first;
					auto f = s.find({dist[dest], dest});
					if(f!=s.end())	{
						s.erase(f);
					}
					dist[dest] = nodeDist+childPair.second;
					s.insert({dist[dest], dest});
				}
			}
		}
		for(auto &d: dist)	{
			if(d.first!=src)	cout<<d.first<<" is located at a distance of "<<d.second<<endl;
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

    Graph<string> India;
    India.addEdge("Amritsar", "Delhi", 1);
    India.addEdge("Amritsar", "Jaipur", 4);
    India.addEdge("Jaipur", "Delhi", 2);
    India.addEdge("Jaipur", "Mumbai", 8);
    India.addEdge("Bhopal", "Agra", 2);
    India.addEdge("Mumbai", "Bhopal", 3);
    India.addEdge("Agra", "Delhi", 1);

    India.dijkstraSSSP("Amritsar");
	
}