//ʵ���������β���� ����������ĺ����ֵ�Լ��������λ��
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	/*��������ĺ�
	�����������飬�������������и������������ֹ���������
	�����������ֵO(n)
	*/
	//�����ö�̬�滮�������ӽṹ

	queue<int> q=queue<int>();    //����������ѭ������
	string k[100][100];    //��¼���������λ��
	cout<<"����������Ԫ�ظ�����"<<endl;
	int num;  //����Ԫ�ظ���
	cin>>num;
	int a[100]={0}; 
	int i=0,j=0;
	cout<<"����������Ԫ�أ�"<<endl;
	for(i=0;i<num;i++)
		cin>>a[i];    //��������Ԫ��

	//������β����ʱ�ı���������жϵ�λ��
	//��n-1������Ԫ�طŵ�����β���γ�������

	for(j=0;j<num-1;j++)
	{
		q.push(a[j]);
	}
	for(j=0;j<num-1;j++)
	{
		a[num+j]=q.front();
		q.pop();
	}
	
	
	//��̬�������
	int b[100][100][2]={0};
	i=0;j=0;
	for(i=0;i<num;i++)
	{
		b[i][0][0]=0;      //��ʼ�������
	    b[i][0][1]=a[i];    //a[i]����ֵ
		k[i][0]="";
		for(j=1;j<num;j++)
		{
		  stringstream ss;
		if(b[i][j-1][0]>=0)     
		{
			
			b[i][j][0]=b[i][j-1][0]+b[i][j-1][1];
			ss<<((i+j-1)%num);
		    ss>>k[i][j];      //д��λ���ַ�����

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
		//�������һ����
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
	

	//�Ƚϸ����������������ֵ
	int max=b[0][0][0];
	int max_i=0;   //��¼���ֵ������
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
	cout<<"����������ֵΪ��"<<max<<endl;

	int si=0,sl=0;
	cout<<"����������Ԫ�������е�λ��Ϊ����0��ʼ����";
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

