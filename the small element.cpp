#include<stdio.h>
#include<stdlib.h>
int a[100];
int m[20];
 int sort(int a[],int l,int r)
 {
 	int i,j;
 	int s;
 	for (i=l;i<=r;i++)
 	{
 		for(j=i+1;j<=r;j++)
 		{
 			if(a[i]>a[j])
 			{
 				s=a[i];
 				a[i]=a[j];
 				a[j]=s;
			 }
		 }
	 }
 }
 
 int select(int a[],int n,int l,int r,int k)
 {
 	int num=r-l+1;
 	int s=num/5;
 	int i=0;
 	int count=0;
 	int mid;
 	int j=0;
 	for(i=l;i<=r;i)
 	{
 		sort(a,i,i+(i+4<=r?4:r-i));
 		m[j]=a[l+(i+4<=r?(i+2):(r+i/2))];
 		count=j++;
 		i+=5;
	 }
	 sort(m,0,count);
	 mid=m[count/2];
	 int a1[100],c1=0;
	 int a2=mid;
	 int a3[100],c3=0;
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]>mid)
	 	{
	 		a3[c3]=a[i];
	 		c3++;
		 }
		else if(a[i]<mid)
		 {
		 	a1[c1]=a[i];
		 	c1++;
		 }
	 }
	
	 if(k<=c1)
	 {
	 	return select(a1,c1,0,c1-1,k);
	 }
	 else if(k>c1+1)
	 {
	 	return select(a3,c3,0,c3-1,k-1-c1);
	 }
	 else if(k=c1+1)
	 {
	 	return a2;
	 }
	 
 }
 
 int main()
 {
 	int k;
 	int n;
 	scanf("%d %d",&n,&k);
 	for (int i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	 }
	 int end = select(a,n,0,n-1,k);
	 printf("the %d small element is %d",k,end);
	 return 0;
 }
