#include <iostream>
using namespace std;

void print_sand(int n,char c)
{
	int a=0,b=0;
	if (n == 1)
	{
		cout<<c<<endl;
		cout<<b<<endl;
		return;
	}
	while (2*a*a-1 < n)
		a++;
	a--;
	b=n+1-2*a*a;
	for (int i=0;i<a;i++)
	{
		for (int j=0;j<i;j++)
			cout<<" ";
		for (int k=2*(a-i)-1;k>0;k--)
			cout<<c;
		cout<<endl;
	}
	for (int i=a-2;i>=0;i--)
	{
		for (int j=0;j<i;j++)
			cout<<" ";
		for (int k=2*(a-i)-1;k>0;k--)
			cout<<c;
		cout<<endl;
	}
	cout<<b<<endl;
}
int main()
{
	int n;
	char c;
	cin>>n;
	cin>>c;
	print_sand(n,c);
	return 0;
}