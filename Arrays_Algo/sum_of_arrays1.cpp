#include<iostream>
using namespace std;
void sumOfTwoArrays(int a[], int b[], int m, int n)  {
    int carry=0, mod=0, sum=0;
    int sumArray[m+1];
    int m_temp=m;
    int n_temp=n;
    while(n_temp>0) {
        sum=carry + a[--m_temp] + b[--n_temp];
        mod=sum%10;
        sumArray[m_temp] = mod;
        carry=sum/10;
    }
    m_temp=m;
    while(m_temp-n>=0)   {
        sum = carry + a[m-n-1];
        carry=sum%10;
        sumArray[m_temp-n] = carry;
        sum/=10;
        m_temp--;
    }
    for(int i=0;i<m+1;i++)  {
        if(sumArray[0]==0)    {
            i++;
            continue;
        }
        cout<<sumArray[i]<<", ";
    }
}

int main()  {
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++) 
        cin>>a[i];
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)    {
        cin>>b[n];
    }
    if(m>n)
        sumOfTwoArrays(a, b, m, n);
    else
        sumOfTwoArrays(b, a, n, m);
    cout<<"END";
    return 0;
}
