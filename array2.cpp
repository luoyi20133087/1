//实现数组的首尾相连 再求子数组的和最大值以及子数组的位置
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	/*求子数组的和
	输入整形数组，数组里有正数有负数，连续数字构成子数组
	求子数组最大值O(n)
	*/
	//解题用动态规划求最优子结构

	queue<int> q=queue<int>();    //建立队列来循环数组
	string k[100][100];    //记录子数组最大位置
	cout<<"请输入数组元素个数："<<endl;
	int num;  //数组元素个数
	cin>>num;
	int a[100]={0}; 
	int i=0,j=0;
	cout<<"请输入数组元素："<<endl;
	for(i=0;i<num;i++)
		cin>>a[i];    //输入数组元素

	//考虑首尾相连时改变数组结束判断的位置
	//将n-1个数组元素放到数组尾部形成新数组

	for(j=0;j<num-1;j++)
	{
		q.push(a[j]);
	}
	for(j=0;j<num-1;j++)
	{
		a[num+j]=q.front();
		q.pop();
	}
	
	
	//动态数组求解
	int b[100][100][2]={0};
	i=0;j=0;
	for(i=0;i<num;i++)
	{
		b[i][0][0]=0;      //初始子数组和
	    b[i][0][1]=a[i];    //a[i]数的值
		k[i][0]="";
		for(j=1;j<num;j++)
		{
		  stringstream ss;
		if(b[i][j-1][0]>=0)     
		{
			
			b[i][j][0]=b[i][j-1][0]+b[i][j-1][1];
			ss<<((i+j-1)%num);
		    ss>>k[i][j];      //写入位置字符数组

			k[i][j]=k[i][j-1]+k[i][j];
		}
		else
		{
		    b[i][j][0]=b[i][j-1][1];
			ss<<((i+j-1)%num);
		    ss>>k[i][j];	
			
		}

		b[i][j][1]=a[i+j];
		}
		stringstream ss;
		//加上最后一个数
	if(b[i][num-1][0]>=0)
	{
		b[i][num][0]=b[i][num-1][0]+b[i][num-1][1];
		ss<<((i+j-1)%num);
		ss>>k[i][num];
		k[i][num]=k[i][num-1]+k[i][num];
	}
	else
	{
		b[i][num][0]=b[i][num-1][1];
		ss<<((i+j-1)%num);
		ss>>k[i][num];
	}

	}
	

	//比较各个子数组最大的求出值
	int max=b[0][0][0];
	int max_i=0;   //记录最大值的坐标
	int max_j=0;
	for(i=0;i<num;i++)
	{
		for(j=0;j<=num;j++)
		{
		if(b[i][j][0]>max)
		{
			max=b[i][j][0];  
			max_i=i;
			max_j=j;
		}
		}
	}
	cout<<"子数组和最大值为："<<max<<endl;

	int si=0,sl=0;
	cout<<"最大子数组各元素数组中的位置为（以0开始）：";
	if(k[max_i][max_j].size()==1)
			cout<<k[max_i][max_j]<<endl;
	else
	{
		si=k[max_i][max_j].size();
		while(si--)
		{
			cout<<k[max_i][max_j][sl++]<<" ";
		}
	}
	cout<<endl;
		return 0;
}

