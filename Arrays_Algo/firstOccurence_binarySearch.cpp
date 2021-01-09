#include<bits/stdc++.h>

using namespace std;

int firstOccurence(int a[], int n, int key)	{
	int start = 0;
	int end = n-1;
	int ans = -1;
	int mid;
	while(start<=end)	{
		mid = start + (end-start)/2;
		if(a[mid]==key)	{
			end = mid-1;
			ans = mid;
		}
		else if(a[mid]>key)	{
			end = mid-1;
		}
		else	start = mid + 1;
	}
	return ans;
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)	{
    		cin>>a[i];
    	}
    	cout<<firstOccurence(a, n, 8);
    	return 0;
	
}