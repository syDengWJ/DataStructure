#include <iostream>
#include <vector>
using namespace std;

/********************
 *求最大子列和
 *算法1:o(N^3)
 ******************/
int maxSubSum1(const vector<int>& v)
{
	int maxSum=0;
	for (int i=0;i<v.size();i++)
	{
		for (int j=i;j<v.size();j++)
		{
			int thisSum=0;
			for (int k=i;k<=j;k++)
			{
				thisSum += v[k];
			}
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

/***********************************
 *求最大子列和
 *算法2:o(N^2)
 **********************************/
 int maxSubSum2(const vector<int>& v)
 {
 	int maxSum = 0;
 	for (int i=0;i<v.size();i++)
 	{
 		int thisSum = 0;
 		for (int j=i;j<v.size();j++)
 		{
 			thisSum += v[j];
 			if (thisSum > maxSum)
 				maxSum = thisSum;
 		}
 	}
 	return maxSum;
 }

 /***********************************
 *求最大子列和算法3
 *递归法:o(Nlog(N))
 **********************************/
 int max(int a,int b,int c)
 {
 	return (a>b?a:b)>c?(a>b?a:b):c;
 }
 int maxSumRec(const vector<int>&v,int left,int right)
 {
 	if (left == right)
 	{
 		if (v[left] > 0)
 			return v[left];
 		else
 			return 0;
 	}
 	int center = (left+right)/2;
 	int  maxLeftSum = maxSumRec(v,left,center);
 	int  maxRightSum = maxSumRec(v,center+1,right);

 	//求出左边最后一个数字结尾的序列最大值
 	int maxLeftBorderSum=0,leftBorderSum=0;
 	for (int i=center;i>=left;--i)
 	{
 		leftBorderSum += v[i];
 		if (leftBorderSum > maxLeftBorderSum)
 			maxLeftBorderSum = leftBorderSum;
 	}
 	//求出右边对后一个数字结尾的序列的最大值
 	int maxRightBorderSum=0,rightBorderSum=0;
 	for (int i=center+1;i<=right;++i)
 	{
 		rightBorderSum += v[i];
 		if (rightBorderSum > maxRightBorderSum)
 			maxRightBorderSum = rightBorderSum;
 	}
 	return max(maxLeftSum,maxRightSum,(maxLeftBorderSum+maxRightBorderSum));
 }

 int maxSubSum3(const vector<int>& v)
 {
 	return maxSumRec(v,0,v.size()-1);
 }

 /***********************************
 *求最大子列和算法4
 *在线处理法:o(N)
 **********************************/
 int maxSubSum4(const vector<int>& v)
 {
 	long maxSum = 0, thisSum = 0; 
    for (int j = 0; j < v.size(); j++) 
    { 
           thisSum += v[j]; 
           if (thisSum > maxSum) 
                  maxSum = thisSum; 
           else if (thisSum < 0) 
                  thisSum = 0; 
    } 
    return maxSum;
 }
 
int main()
{
	std::vector<int> v;
	int *a;
	int n;
	cin>>n;
	a = new int[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	cout<<maxSubSum3(v)<<endl;
	return 0;
}