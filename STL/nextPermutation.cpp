#include<iostream>
#include<algorithm>
using namespace std;

// To find next permutation of the numbers in the array or sort the array if next permutaion does not exist
int permute	(int a[], int n)	{
	if(next_permutation(a, a+n))    {
        for(int i=0;i<n;i++)	
			cout<<a[i]<<" ";
    }
	else	{ 
		sort(a, a+n);
		for(int i=0;i<n;i++)	
			cout<<a[i]<<" ";
	}

	return 0;
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)	{
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++)
			cin>>a[j];
		permute(a, n);
        cout<<endl;
	}
	return 0;
}