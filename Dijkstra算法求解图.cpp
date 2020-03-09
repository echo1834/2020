#include<stdio.h>
#include<stdlib.h>
#define maxsize 10000010
int a[1000][1000];
int dis[1000];
int f[1000];
int i, j, k,m,n;
int main() {
	scanf("%d%d",&n,&m);
	int    min;
	int    x,y,z;
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	for( i=1; i<=n; i++)
		dis[i]=maxsize;
	dis[1]=0;
	for(i=1; i<=n; i++) {
		min = maxsize;
		for(j=1; j<=n; j++)
			if(!f[j]&&dis[j]<min) {
				min=dis[j];
				k=j;
			}
		f[k] = 1;
		for(j=1; j<=n; j++)
			if(a[k][j]!=0&&!f[j]&&dis[j]>dis[k]+a[k][j])
				dis[j]=dis[k]+a[k][j];
	}
	for(i=1; i<n; i++)
		printf("%d->",dis[i]);
	printf("%d\n",dis[n]);
	return 0;
}
