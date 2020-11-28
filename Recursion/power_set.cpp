#include<iostream>

using namespace std;

void power_set(char *in, char *out, int i, int j)	{
	//base case
	if(in[i]=='\0')	{
		out[j]='\0';
		cout<<out<<endl;
		return;
		}

	//rec case
	//include the current char

	out[j] = in[i];
	power_set(in, out, i+1, j+1);

	//exclude the current char

	power_set(in , out, i+1, j); 
}

int main()	{

	char input[] ="cbad";
	char output[10];

	power_set(input, output, 0, 0);
}