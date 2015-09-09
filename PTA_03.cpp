#include <iostream>
using namespace std;

void move_numbers(int *a,int n,int k)
{
	if (k<0)
		k = n-(-k)%n;
	else
		k %= n;
	int r=0;
	int p=0;
	do
	{
		r = n % k;
		p = n / k;
		for (int j=1;j<p;j++)
		{
			for (int i=0;i<k;i++)
			{
				int tmp=a[i+k*j];
				a[i+k*j]=a[i];
				a[i]=tmp;
			}
		}
		for (int i=0;i<r;i++)
		{
			int tmp = a[i+p*k];
			a[i+p*k] = a[i];
			a[i] = tmp;
		}
		n=k;
		k=k-r;
	}while (r!=0);
		
	for (int i=0;i<n;i++)		
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	int *arr;
	int k;
	cin>>n;
	cin>>k;
	arr=new int[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	move_numbers(arr,n,k);
	return 0;
}