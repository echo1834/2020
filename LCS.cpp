#include<stdio.h>
#include<string.h>
int s1[100][100];
int s2[100][100];
int LCS_Length(char x[100],char y[100]) {
	int m=strlen(x);
	int n=strlen(y);
	int i,j;
	memset(s1,0,sizeof(s1)); //根据递归方程的第一种情况，先初始化数组s1[][]
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++) {
			if(x[i-1] == y[j-1]) {
				s1[i][j]=s1[i-1][j-1]+1;
				s2[i][j]=1;
			} else if(s1[i-1][j] >= s1[i][j-1]) {
				s1[i][j]=s1[i-1][j];
				s2[i][j]=2;
			} else {
				s1[i][j]=s1[i][j-1];;
				s2[i][j]=3;
			}
		}
	return s1[m][n];
}
void Print_LCS(char X[100],int i,int j) { //输出最优解
	if( (i == 0) || (j == 0) )
		return;
	if(s2[i][j] == 1) {
		Print_LCS(X,i-1,j-1);
		printf("%c",X[i-1]);
	} else if(s2[i][j] == 2)
		Print_LCS(X,i-1,j);
	else
		Print_LCS(X,i,j-1);
}
int main() {
	char  X[100],Y[100];
    while(gets(X)&&gets(Y)) {
		int p=LCS_Length(X,Y);
		printf("这两个字符串的LCS为：%d\n",p);
		printf("该公共子序列为:");
		Print_LCS(X,strlen(X),strlen(Y));
	}
	return 0;
}
