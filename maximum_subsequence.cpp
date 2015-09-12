#include <iostream>
using namespace std;
/********************************
 *
 *求最大子列算法：改自算法4
 *
 ********************************/
 int maximum_subsequence(int *a,int n,int &start,int &end)
 {
 	int sum=0,tempSum=0;
 	int tempi=0,tempj=0;
 	for (int i=0;i<n;i++)
 	{
 		if (tempSum >=0)
 		{
 			tempSum += a[i];
 			tempj = i;
 		}
 		else
 		{
 			tempSum = a[i];
 			tempi = i;
 			tempj = i;
 		}
 		if (tempSum > sum || (tempSum == 0 && end == 0))
 		{
 			sum = tempSum;
 			start = tempi;
 			end = tempj;
 		}
 	}
 	return sum;
 }
int main()
{
	int n,start(0),end(0);
	cin>>n;
	int *a;
	a=new int[n];
	for (int i=0;i<n;i++)
		cin>>a[i];
	cout<<maximum_subsequence(a,n,start,end)<<" "
		<<start<<" "<<end<<endl;		//这里的start和end是0,0
	cout<<start<<" "<<end<<endl;		//这里的是正确结果，不知道为什么？？？
	return 0;
}