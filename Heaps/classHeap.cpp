#include<bits/stdc++.h>

using namespace std;

class Heap	{
	vector<int> v;
	bool minHeap;

	bool compare(int a, int b)	{
		if(minHeap)	return a<b;
		return b<a;
	}

	void heapify(int idx)	{
		int left = 2*idx, right = 2*idx+1, min_idx=idx;
		if(left<v.size() and compare(v[left], v[idx]))	{
			min_idx = left;
		}
		if(right<v.size() and compare(v[right], v[min_idx]))	{
			min_idx=right;
		}
		if(min_idx!=idx)	{
			swap(v[min_idx], v[idx]);
			heapify(min_idx);
		}
		return;
	}

public:
	Heap(bool type=true)	{
		v.push_back(-1);
		minHeap = type;
	}

	void print()	{
		for(int i=1;i<v.size();++i)	cout<<v[i]<<" ";
	}

	void push(int d)	{
		v.push_back(d);
		int idx = v.size()-1;
		int parent = idx/2;

		while(idx>1 and compare(v[idx], v[parent]))	{
			swap(v[idx], v[parent]);
			idx = parent;
			parent/=2;
		}
	}

	int top()	{
		return v[1];
	}

	void pop()	{
		swap(v[1], v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}

	bool empty()	{
		return v.size()==1;
	}
};

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

    Heap h(true);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)	{
    	int x;
    	cin>>x;
    	h.push(x);
    	h.print();
    	cout<<endl;
    }
    while(!h.empty())	{
    	cout<<h.top()<<" ";
    	h.pop();
    }

	return 0;
}