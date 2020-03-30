#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 1e6;
struct node {
	double x;
	double y;
}dis[1000];

double distance(int l, int r)
{
	return sqrt((dis[l].x - dis[r].x) * (dis[l].x - dis[r].x) + ((dis[l].y - dis[r].y) * (dis[l].y - dis[r].y)));
}

double min(double l, double r)
{
	if (l<r)
	return l;
	else 
	return r;
}


double getresult(int l, int r)
{
	double end = max ;
	int i = 0;
	int j = 0;
	int k = 0;

	if (l == r)
		return end;
	if (r - l == 1)
		return distance(l, r);
	double distancel = getresult(l, (l + r) / 2);
	double distancer = getresult((l + r) / 2+1, r);

	end = min(distancel, distancer);

	int t[1000] = { 0 }; 

	for (i = l; i <= r; i++)
	{
		if (fabs(dis[(l + r) / 2].x - dis[i].x) <= end)
			t[k++] = i; 
	}
	for (i = 0; i <= k - 1; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (dis[t[j]].y - dis[t[i]].y < end)
				end = min(end, distance(t[i], t[j]));
	return end;
}

int flag(const void *a,const void* b)
{
	struct node aa=*(struct node *)a;
	struct node bb=*(struct node *)b;
	return aa.x-bb.x;
}

int main()
{
	int n = 1;
	while (scanf("%d", &n) !=EOF)
	{
		if(n==0)
		break;
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &dis[i].x, &dis[i].y);
		qsort(dis, n, sizeof(dis[0]), flag);
		printf("×î½üµã¾àÀë£º%lf\n", getresult(0, n - 1) );
	}
	return 0;
}
