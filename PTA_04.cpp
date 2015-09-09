#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string numbers(string s)
{
	string t;
	int carry=0;
	for (int i=s.size()-1;i>=0;--i)
	{
		char c=((s[i]-'0')*2+carry)%10+'0';
		t = c + t;
		carry=((s[i]-'0')*2+carry)/10;
	}
	if (carry != 0)
		return '1'+t;
	else
		return t;
}

bool comp(string s,string t)
{
	vector<int>  v(10,0);
	if (s.size() != t.size())
		return false;
	for (int i=0;i<s.size();i++)
	{
		++v[s[i]-'0'];
	}
	for (size_t i=0;i<t.size();++i)
		--v[t[i]-'0'];
	for (size_t i=0;i<10;++i)
		if (v[i] !=0)
			return false;
	return true;
}
int main()
{
	string s;
	cin>>s;
	string t=numbers(s);
	if (comp(s,t))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<t;
	return 0;
}