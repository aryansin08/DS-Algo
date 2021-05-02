#include<bits/stdc++.h>

using namespace std;

stack<int> reverse(stack<int> st)	{
	stack<int> aux;
	int temp;

	int n = st.size();

	while(n--)	{
		temp = st.top();
		st.pop();

		for(int i=0;i<n and !st.empty();++i)	{
			int top = st.top();
			st.pop();
			aux.push(top);
		}

		st.push(temp);

		while(!aux.empty())	{
			int top = aux.top();
			aux.pop();
			st.push(top);
		}	

	}
	return st;
}

//Recursive Reverse

void insertAtBottom(stack<int> &st, int x)	{
	if(st.empty())	{
		st.push(x);
		return;
	}

	int data = st.top();
	st.pop();
	insertAtBottom(st, x);
	st.push(data);

}

void recursiveRev(stack<int> &st)	{
	if(st.empty())	return;

	int x = st.top();
	st.pop();
	recursiveRev(st);
	insertAtBottom(st, x);

}

//END

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
	stack<int> st;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)	st.push(i);

	stack<int> reversedStack = reverse(st);

	stack<int>temp = st;

	while(!st.empty())	{
		cout<<st.top()<<" ";
		st.pop();
	}

	cout<<endl;
	st = temp;
	recursiveRev(st);

	while(!st.empty())	{
		cout<<st.top()<<" ";
		st.pop();
	}

	cout<<endl;

	while(!reversedStack.empty())	{
		cout<<reversedStack.top()<<" ";
		reversedStack.pop();
	}
	return 0;
}