#include <iostream>
using namespace std;
int search(int a[][50],int n,int m,int k){
    int i=0;
    int j=m-1;
    while(i<=n-1&&j>=0){
        if(k==a[i][j]){
            return 1;
            
        }
        else if(k>a[i][j]){
             i++;
        }
        else{
            j--;
        }
        
    }
	return 0;
    
}

int main()
{
    int n,m,k;
    cin>>n>>m;
    int a[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cin>>k;
   int ans=search(a,n,m,k);
     cout<<ans;
    return 0;
}
