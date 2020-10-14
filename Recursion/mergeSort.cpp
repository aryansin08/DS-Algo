#include<iostream>

using namespace std;

void merge(int *a, int start, int end)	{
	int mid = start + (end-start)/2;
	int i = start, j = mid+1, k = start;
	int temp[end];
	static int count =0;
	while(i<=mid && j<=end)	{
		if(a[i]<a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i<=mid)
		temp[k++] = a[i++];
	while(j<=end)
		temp[k++] = a[j++];
		
	for(int i=start;i<=end;i++)	{
		a[i] = temp[i];
	}
//	cout<<"Pass : "<<count++<<endl;
//	cout<<"\n Start :"<<start<<" End : "<<end<<endl;
//	for(int i=start;i<=end;i++)
//		cout<<temp[i]<<" ";
//	cout<<endl;
}

void mergeSort(int a[], int start, int end)	{
	if(start>=end)
		return;
	
	int mid = start + (end-start)/2;
	
	mergeSort(a, start, mid);
	mergeSort(a, mid+1, end);
	merge(a, start, end);
}

int main()	{
	int a[] = {3, 5, 1, 9, 6, 11, 7, 14, 12};
	for(int i=0;i<9;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	mergeSort(a, 0, 8);
	for(int i=0;i<9;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
