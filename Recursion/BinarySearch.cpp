#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int low, int high, int key)	{
	int mid = low + (high-low)/2;
	if(a[mid]==key)
		return mid;
	else if(a[mid]>key)
		return binarySearch(a, low, mid-1, key);
	else 
		return binarySearch(a, mid+1, high, key);
	
	return -1;
}

int main()	{
	int a[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	cout<<binarySearch(a, 0, 10, 89);
	return 0;
} 
