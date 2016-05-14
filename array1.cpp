/*
求子数组的和
输入整形数组，数组里有正数有负数，连续数字构成子数组
求子数组最大值O(n)
*/
#include<iostream>
using namespace std;

int main()
{
	
	//解题用动态规划求最优子结构

	cout<<"请输入数组元素个数："<<endl;
	int num;  //数组元素个数
	cin>>num;
	cout<<"请输入数组元素："<<endl;
	int a[100]={0}; 
	for(int i=0;i<num;i++)
		cin>>a[i];    //输入数组元素

	//考虑首尾相连时改变数组结束判断的位置

	//动态求解
	int b[100][100];
	b[0][0]=0;      //初始子数组和
	b[0][1]=a[0];    //a[i]数的值
	for(int i=1;i<num;i++)
	{
		if(b[i-1][0]>=0)
			b[i][0]=b[i-1][0]+b[i-1][1];
		else
		    b[i][0]=b[i-1][1];
		b[i][1]=a[i];
	}
	//加上最后一个数的判断
	if(b[num-1][0]>=0)
		b[num][0]=b[num-1][0]+b[num-1][1];
	else
		b[num][0]=b[num-1][1];
	//比较各个子数组最大的求出值
	int max=b[0][0];
	for(int i=1;i<=num;i++)
	{
		if(b[i][0]>max)
			max=b[i][0];
	}
	cout<<"子数组和最大值为："<<max<<endl;
	return 0;
}

