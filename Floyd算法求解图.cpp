#include<stdio.h>
#include<stdlib.h>
#define max 10000000
int dis[1000][1000];
int flow[1000][1000];
int main() {
	int i,j,k,m,n;
	int x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) {
			dis[i][j]=max;
			flow[i][j]=j;
		}

	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=z;
		dis[y][x]=z;
	}

	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++) {
				if(dis[i][k]+dis[k][j]<dis[i][j]) {
					dis[i][j]=dis[i][k]+dis[k][j];
					flow[i][j]=flow[i][k];
				}
			}
	for(i=1; i<=n; i++)
		for(j=1; j<=i; j++)
			if (i!=j) printf("%d-%d:%d\n",i,j,dis[i][j]);
	int x, y;
	scanf("%d%d",&x,&y);
	while (x!=y) {
		printf("%d-",x);
		x=flow[x][y];
	}
	printf("%d\n",y);
	return 0;
}
