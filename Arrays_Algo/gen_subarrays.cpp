#include<bits/stdc++.h>
using namespace std;
 int main()	{
 	int i, j, k;
 	int max = 0;
 	int a[] = {1, 2, 3, 4, 5, 6, 7};
 	for(i=0;i<7;i++)	{
 		for(j = i;j<7;j++)	{
 			int sum = 0;
 			for(k = i;k<=j;k++)	{
 				sum+=a[k];
			 }
 			if(sum>max)
			 	max = sum;	
 			cout<<endl;
		 }
	 }
	cout<<max;
 	return 0;
 }
