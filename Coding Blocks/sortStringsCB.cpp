#include<bits/stdc++.h>
using namespace std;

//https://hack.codingblocks.com/app/practice/1/1042/problem

//Sort string on a given key number that corresponds to a number inside the string itself

unordered_map<string, int> m1;
unordered_map<string, string> m2;

bool cmpNumeric(string a, string b)	{
	return m1[a]<m1[b];
}
bool cmpString(string a, string b)	{
	return m2[a]<m2[b];
}

string extractStringAtKey(string str, int key)	{
	string s = strtok((char*)str.c_str(), " ");
	while(key>1)	{
		s = strtok(NULL, " ");
		key--;
	}
	return s;
}

void sort(vector<string> &v, int key, string rev, string s)	{
	if(s[0]=='n')	{
		for(auto &x: v)	{
			string str = extractStringAtKey(x, key);
			int i = str.size()-1, p=1, num = 0;
			while(i>=0)	{
				num+=p*(str[i--]-'0');
				p*=10;
			}
			m1[x] = num;
		}
		sort(v.begin(), v.end(), &cmpNumeric);
	}
	else	{
		for(auto &x: v)	{
			string str = extractStringAtKey(x, key);
			m2[x] = str;
		}
		sort(v.begin(), v.end(), &cmpString);
	}
	if(rev[0]=='t')	reverse(v.begin(), v.end());
	return;
}
int main() {
	int t;
	cin>>t;
	cin.get();
	vector<string> nums(t);
    for(int i=0;i<t;++i)    getline(cin, nums[i]);
	int key;
	cin>>key;
	string rev, s;
	cin>>rev>>s;
	sort(nums, key, rev, s);
	for(auto &x: nums)	cout<<x<<endl;
	return 0;
}

/*	Input
	3
	92 022
	82 12
	77 13
	2 false numeric

	Output
	82 12
	77 13
	92 022
*/