#include <iostream>
#include <string>
using namespace std;

void shuffting(string *a,int *b,int n,int k)
{
	string *p=new string[n];
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<n;j++)
			p[b[j]-1]=a[j];
		for (int j=0;j<n;j++)
			a[j]=p[j];
	}
	for (int i=0;i<n-1;i++)
		cout<<p[i]<<" ";
	cout<<p[n-1]<<endl;
	delete []p;
}

int main()
{
	string a[54];
	int b[54];
	string c[4]={"S","H","C","D"};
	for (int i=0;i<4;++i)
	{
		for (int j=0;j<13;++j)
		{
			if (j<9)
				a[j+13*i]=c[i]+char(j+'0'+1);
			else
				a[j+13*i]=c[i]+"1"+char((j+1)%10+'0');
		}
	}
	a[52]="J1";
	a[53]="J2";
	int k=0;
	cin>>k;
	for (int i=0;i<54;++i)
		cin>>b[i];
	shuffting(a,b,54,k);
	return 0;
}
