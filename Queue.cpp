#include<bits/stdc++.h>

using namespace std;

class Queue	{
	vector<int> queue;
	int f, r, currSize, maxSize;

public:
	Queue(int ds = 5)	{
		queue.resize(ds);
		currSize = 0;
		maxSize = ds;
		f = 0;
		r = maxSize - 1;
	}

	bool full()	{
		return currSize==maxSize;
	}

	void push(int key)	{
		if(!full())	{
			r = (r+1)%maxSize;
			queue[r] = key;
			currSize++;
		}
	}

	bool empty()	{
		return currSize==0;
	}

	void pop()	{
		if(!empty())	{
			f = (f+1)%maxSize;
			currSize--;
		}
	}

	int front()	{
		if(!empty())	return queue[f];
		return -1;
	}

};

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	
	Queue q;

	for(int i=1;i<=6;++i)	{
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(7);

	while(!q.empty())	{
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}