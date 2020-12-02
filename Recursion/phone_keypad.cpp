//To generate all permutations of the corresponding alphabets of the numbers on a phone keypad

#include<bits/stdc++.h>

using namespace std;

void generate_names(char *in, char *out, int i, int j)	{
	char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

	// base case
	if(in[i]=='\0')	{
	out[j]='\0';
	cout<<out<<endl;
	return;
	}

	int digit = in[i] - '0';

	//rec case
	if(digit==0 || digit==1)	{
		generate_names(in, out, i+1, j);
	}

	for(int k=0; keypad[digit][k]!='\0'; k++)	{
		out[j] = keypad[digit][k];
		//fill remaining part with recursive call
		generate_names(in, out, i+1, j+1);
	}
}

int main()	{
	char input[] = "27926";
	char out[10];
	generate_names(input, out, 0, 0);
	return 0;
}