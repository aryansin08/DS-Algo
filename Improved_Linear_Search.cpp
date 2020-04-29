using namespace std;
#include<bits/stdc++.h>
void swap(int x, int y)	{
		int temp = 0;
		temp=x;
		x=y;
		y=temp;
}

int LinearSearch(int arr[], int key, int n)	{
		for(int i=0;i<n;i++)	{
			if(arr[i]==key)	{
				swap(arr[i], arr[i-1]);
				return i;
			}
		}
		return -1;
}

int main()	{
	int arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter Key to be Searched : "<<endl;
	int key;
	cin>>key;
	int result = LinearSearch(arr, key, n); 
   (result == -1)? cout<<"Element is not present in array" : cout<<"Element is present at index " <<result; 
   return 0; 
}
