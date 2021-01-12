#include<bits/stdc++.h>

using namespace std;

//Use of Binary Search

bool canPlaceCows(int a[], int n, int c, int min_sep)	{

	int last_cow = a[0];
	//Place a cow in th first stall
	int count=1;
	for(int i=1;i<n;i++)	{
		if(a[i] - last_cow>=min_sep)	{
			last_cow=a[i];
			count++;
			if(count==c)
				return true;
		}
	}
	return false;

}

//Using binSearch to place C cows at N stalls located at positions a[i] 
int cows(int a[], int n, int c)	{
	int s = 0, e=a[n-1]-a[0];
	int ans = 0;
	while(s<=e)	{
		int mid = (s + e)/2;
		cout<<mid<<endl;
		bool canPlacecow = canPlaceCows(a, n, c, mid);
		if(canPlacecow)	{
			ans = mid;
			s = mid+1;
		}
		else	{
			e = mid-1;
		}

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
	int t;
	cin>>t;
	while(t--)	{
		int n, c;
		cin>>n>>c;
		int a[n];
		for(int i=0;i<n;i++)	{
			cin>>a[i];
		}
		sort(a, a+n);
		cout<<cows(a, n, c)<<endl;
	}	
	return 0;
}