#include<bits/stdc++.h>

//Generate string map from a given number stream as a string

using namespace std;
vector<string> ans;

void genStrings(string input, string output, int i, int j)	{
	if(i>=input.size())	{
		ans.push_back(output.substr(0, j));
		return;
	}

	int digit = input[i]-'0';
	output[j]=digit + 'A'-1;
	genStrings(input, output, i+1, j+1);

	if(i+1<input.size())	{
		int second_digit = 10*digit + input[i+1]-'0';
		if(second_digit<26)	{
			output[j] = second_digit + 'A'-1;
			genStrings(input, output, i+2, j+1);
		}
	}
	return;
}

int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    string in, out;
    cin>>in;
    out.resize(in.size());
    genStrings(in, out, 0, 0);
    for(auto &v:ans)	cout<<v<<" ";
	return 0;
}