#include<bits/stdc++.h>
using namespace std;
void rotate(int a[][4], int m, int n)	{
	int i, j;
	//Reverse Row elements
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n/2;j++)
			swap(a[i][j], a[i][n-j-1]);
	}
		
	//Transpose	
	for(i = 0;i<m;i++)	{
		for(j = 0;j<n;j++)	{
			if(i<j)
			swap(a[i][j], a[j][i]);
			}	
		}
	}
	
void rotate_stl(int a[][4], int m, int n)	{
	
	//STL Reverse
	for(int i=0;i<n;i++)	{
		reverse(a[i], a[i] + m);
	}
	
	
	//Transpose	
	for(int i = 0;i<m;i++)	{
		for(int j = 0;j<n;j++)	{
			if(i<j)
			swap(a[i][j], a[j][i]);
			}	
		}
}

int main()	{
	int a[][4] = {{2, 4, 9, 16}, {25, 36, 49, 64}, {81, 100, 121, 144}, {169, 196, 225, 256}};
	int b[][4] = {{2, 4, 9, 16}, {25, 36, 49, 64}, {81, 100, 121, 144}, {169, 196, 225, 256}};
	cout<<"Array before rotation : "<<endl;
	for(int i = 0; i<4;i++)	{
		for(int j=0;j<4;j++)	{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	rotate(a, 4, 4);
	cout<<"Array after 90 anticlockwise : "<<endl;
	for(int i = 0; i<4;i++)	{
		for(int j=0;j<4;j++)	{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	rotate_stl(b, 4, 4);
	cout<<"Array after rotation using STL : "<<endl;
	for(int i = 0; i<4;i++)	{
		for(int j=0;j<4;j++)	{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
