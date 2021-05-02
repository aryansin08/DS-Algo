#include<bits/stdc++.h>

using namespace std;

void largestRectangleArea(vector<int> &A) {
    int maxArea = 0, n = A.size();
    stack<int> st;
    for(int i=0;i<n;++i) {
        if(st.empty() or A[st.top()]<=A[i])	st.push(i);


        else if(A[st.top()]>A[i])   {
            while(!st.empty() and A[st.top()]>A[i])    {
                int top = st.top();
                st.pop();
                if(st.empty())  maxArea = max(maxArea,A[top]*i);
                else    maxArea = max(maxArea, A[top]*(i-st.top()-1));
            }
        	st.push(i);
        }
    }
    while(!st.empty())  {
        int top = st.top();
        st.pop();
        if(st.empty())  maxArea = max(maxArea,A[top]*n);
        else    maxArea = max(maxArea, A[top]*(n-st.top()-1));
    }
    cout<<endl<<maxArea;
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	vector<int> v{2,1,5,6,2,3};
    	largestRectangleArea(v);
    	return 0;
	
}