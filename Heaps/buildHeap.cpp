#include<bits/stdc++.h>

using namespace std;

bool minHeap=false;

bool compare(int a, int b)	{
	if(minHeap)	return a<b;
	return a>b;
}

//O(NlogN) Method;
void buildHeap(vector<int> &heap)	{
	for(int i=2;i<heap.size();++i)	{
		int idx = i;
		int parent = i/2;
		while(idx>1 and compare(heap[idx], heap[parent]))	{
			swap(heap[idx], heap[parent]);
			idx=parent;
			parent/=2;
		}
	}
	return;
}

//O(N) Method;
void heapify(vector<int> &v, int idx)	{
		int left = 2*idx, right = 2*idx+1, min_idx=idx;
		if(left<v.size() and compare(v[left], v[idx]))	{
			min_idx = left;
		}
		if(right<v.size() and compare(v[right], v[min_idx]))	{
			min_idx=right;
		}
		if(min_idx!=idx)	{
			swap(v[min_idx], v[idx]);
			heapify(v, min_idx);
		}
		return;
	}

void buildHeapOptimized(vector<int> &heap)	{
	for(int i=(heap.size()-1)/2;i>0;--i)	{
		heapify(heap, i);
	}
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);

    	vector<int> v1{-1,10,20,5,6,1,8,9,4};
    	// minHeap=true;
    	buildHeap(v1);
    	for(auto &x:v1)	cout<<x<<" ";

    	cout<<endl;

    	vector<int> v2{-1,10,20,5,6,1,8,9,4};
    	buildHeapOptimized(v2);
    	for(auto &x:v2)	cout<<x<<" ";

	#endif

	return 0;
}