#include<iostream>
using namespace std;
const int MAX=100000000;
int const M=7;
void Maxchain(int *p,int Length,int m[][M],int s[][M])
{
	int q,n=Length-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	/* �������ĳ��� */
	{
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         
			m[i][j]=MAX;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void Print(int s[][M],int i,int j)
{
	if(i == j) cout<<"A"<<i;
	else
	{
		cout<<"(";
		Print(s,i,s[i][j]);
		Print(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
    int p[M]={30,35,15,5,10,20,25};
    int num;
	cout<<"����Ҫ�����������ǰ�������� "; 
	cin>>num;
	int m[M][M],s[M][M];
	Maxchain(p,M,m,s);
	cout<<"��n="<<num<<"ʱ���Ž�Ϊ: \n"<<m[1][num];
	cout<<"\n���Ż�����Ϊ��\n"; 
	Print(s,1,num);
	return 0;
}
