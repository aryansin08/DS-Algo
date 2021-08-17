#include<bits/stdc++.h>

using namespace std;

/*Allocate n no of books with a[i] pages to m students
 such that the maximum number of pages read by a single
  student is minimized*/

/*Function to find out weather curr_min pages
 can be alloted to a single student while exhausting
 the total number of books for all students*/
bool isPossible(int a[], int n, int m, int curr_min)	{
	int student = 1;
	int pages = 0;
	for(int i=0;i<n;i++)	{
		if(pages+a[i]>curr_min)	{
			student++;
			pages = a[i];
			if(student>m)
				return false;
		}
		else {
			pages+=a[i];
		}
	}
	return true;
}

/*Using Binary Search to find the minimum
 of the maximum pages a single student reads*/

int find_pages(int a[], int n, int m)	{
	int sum = 0;

	if(n<m)
		return -1;

	for(int i=0;i<n;i++)
		sum+=a[i];

	int l = a[n-1], r = sum;
	int ans = INT_MAX;

	while(l<=r)	{
		int mid = (l+r)/2;
		if(isPossible(a, n, m, mid))	{
			ans = min(ans, mid);
			r = mid-1;
			/*Since if a student can read mid no of pages
			 then there exists a configuration where a student
			  can read more than mid pages*/
			  
		}
		else
			l = mid+1;
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
    int a[] = {10, 20, 30, 40};
    cout<<find_pages(a, 4, 2);
    return 0;
	
}