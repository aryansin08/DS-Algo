#include<bits/stdc++.h>
using namespace std;
int binary(int l, int h, int c)	{
	char y;
	static int mid=(h+l)/2;
	cout<<"Q."<<c<<" Is your number greater than or lower than "<<mid<<" ?";
	c++;
	cout<<endl<<"Enter 'g' for greater or 'l' for lower or 'f' if "<<mid<<" is your number : ";
	cin>>y;
	if(y=='g')	{
		l=mid;
		mid=(h+l)/2;
		if(l<mid)
			binary(l, h, c);
		else
			cout<<"The number in your mind is "<<mid+1;
			return 0;
	}
	else if(y=='l')	{
		h=mid;
		mid=(h+l)/2;
		if(l<mid)
			binary(l, h, c);
		else 
			cout<<"The number in your mind is "<<mid+1;
			return 0;
	}
	else if(y=='f')	{
			cout<<"Found your number "<<mid<<" after "<<c--<<" tries!!";
			return 0;
	}
}
int main()	{
	int n, c=1;
	cout<<"Enter the range you want your number to be guessed in :"<<endl;
	cin>>n;
	cout<<"Now I'll ask you a maximum of "<<int(log2(n)+1)<<" questions"<<endl;
	int l=0;
	binary(l, n, c);
	return 0;
}
