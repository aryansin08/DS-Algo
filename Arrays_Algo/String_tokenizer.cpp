#include<bits/stdc++.h>
using namespace std;

char *mystrtok(char *str, char delim)	{
	static char *input=NULL;
	if(str!=NULL)	{
		input=str;
	}
	char *output = new char[strlen(input)+1];
	int i=0;
	for(;input[i]!='\0';i++)	{
		if(input[i]!=delim)
			output[i] = input[i];
		else	{
			output[i]='\0';
			input=input+i+1;
			return output;
		}
	}
	//Handle end of string
	if(input[i]='\0')
		output='\0';
		input=NULL;
		return output;
	if(input==NULL)
		return NULL;
}

int main()	{
	char s[100] = "My name is Aryan";
	char *ptr=mystrtok(s, ' ');
	cout<<ptr<<endl;
	
	while(ptr!=NULL)	{
		ptr=mystrtok(NULL, ' ');
		cout<<ptr<<endl;
	}
}
