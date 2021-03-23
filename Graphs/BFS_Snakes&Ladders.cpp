#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph	{
	map<T, list<T>> l;
public: 
	void addEdge(int x, int y)	{
		l[x].push_back(y);
	}

	 int bfs(T src, T dest)	{
		map<T, int> dist;
		map<T, T> parent;
		parent[src]=src;
		queue<T> q;
		q.push(src);
		for(auto node_pair:l)	{
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;
		while(!q.empty())	{
			T node = q.front();
			q.pop();
			// cout<<node<<" ";
			for(auto nbr : l[node])	{
				if(dist[nbr]==INT_MAX)	{
					q.push(nbr);
					dist[nbr] = dist[node]+1;
					parent[nbr]=node;
				}
			}
		}
		// cout<<endl;
		// for(auto node_pair:l)	{
		// 	T node = node_pair.first;
		// 	int d = dist[node];
		// 	cout<<"Node "<<node<<" Dist from src "<<d<<endl;
		// }

		//Print the path of the counter
		int temp=dest;
		while(temp!=src)	{
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;
		return dist[dest];
	}
};
int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	vector<int> board(37, 0);
    	int snakes;
    	cout<<"Enter no of snakes : ";
    	cin>>snakes;
    	int ladders;
    	cout<<"\nEnter no of ladders : ";
    	cin>>ladders;
    	cout<<endl;
    	cout<<"Enter snake positions and falls"<<endl;
    	for(int i=0;i<snakes;++i)	{
    		int pos, fall;
    		cin>>pos>>fall;
    		board[pos] = fall;
    	}
    	cout<<"\nEnter ladder positions and jumps"<<endl;
    	for(int i=0;i<ladders;++i)	{
    		int pos, jump;
    		cin>>pos>>jump;
    		board[pos] = jump;
    	} 
    	Graph<int> g;
    	for(int i=0;i<=36;++i)	{
    		for(int dice=1;dice<=6;++dice)	{
    			int j = i+dice;
    			j+=board[j];
    			if(j<=36)	{
    				g.addEdge(i, j);
    			}
    		}
    	}
    	g.addEdge(36,36);

    	cout<<g.bfs(0, 36);
    	return 0;
	
}

/*Sample Input
5 5
17 -13
20 -14
24 -8
32 -2
34 -22
2 13
5 2
9 18
18 11
25 10

Output
36<--30<--29<--15<--0
4
*/