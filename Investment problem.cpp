#include <iostream>
#include <math.h>
using namespace std;
const int X = 5;
const int Y = 6;
int x[5]={0};
	int m[X][Y]={0};
	int F[X][Y] = { 0 };
int max(int F[X][Y],int f[X][Y],int mm,int money)
{
    
	for (int i = 1; i <= mm; i++)
	{
		for (int j = 0; j <= money; j++)
		{
			F[i][j] = 0;
			m[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				if (F[i][j] < f[i][k] + F[i - 1][j - k]){
					F[i][j] = f[i][k] + F[i - 1][j - k];
					m[i][j]=k;}
			}
		}
	}
	return F[mm][money];
}

void jie(int mm, int money,int x[5],int F[X][Y])
{
  for(int i=mm;i>=1;i--)
  {
    x[i]=m[i][money];
    money=money-x[i];
    cout<<"the "<<i<<"get--"<<x[i]<<endl;
  }
  
}
int main(int argc, char** argv)
{
	
	
	int f[X][Y] = { 0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24 };
	int money;
	cin>>money;

	cout <<"max profit is:"<<max(F, f, 4, money)<<endl;
	jie(4,money,x,F); 
	system("pause");
	return 0;
}
