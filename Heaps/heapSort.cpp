#include<bits/stdc++.h>

using namespace std;

bool minHeap=false;

bool compare(int a, int b)	{
	if(minHeap)	return a<b;
	return a>b;
}

void heapify(vector<int> &v, int idx, int size)	{
	int left = 2*idx+1, right = left+1, max_idx=idx;

	if(left<size and compare(v[left], v[idx]))	{
		max_idx = left;
	}
	if(right<size and compare(v[right], v[max_idx]))	{
		max_idx=right;
	}

	if(max_idx!=idx)	{
		swap(v[max_idx], v[idx]);
		heapify(v, max_idx, size);
	}
}

void buildHeap(vector<int> &v)	{
	for(int i=(v.size()-1)/2;i>=0;--i)	{
		heapify(v, i, v.size());
	}
}

void heapSort(vector<int> &v)	{

	buildHeap(v);

	int size = v.size();
	while(size>0)	{
		swap(v[0], v[--size]);
		heapify(v, 0, size);
	}
	return;
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);

    	vector<int> v{10,20,5,6,1,8,9,4};

    	heapSort(v);

    	for(auto &x : v)	cout<<x<<" ";

	#endif
	
}