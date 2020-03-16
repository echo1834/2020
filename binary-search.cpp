#include<stdio.h>
int main(void){
	int arr[]={4,6,10,11,13,16,19,22,35,45,57,66,73,78,83,87,89,95,102,110,124,127,129,141,161,189};
	int n,i,count=0;
	int len=sizeof(arr)/sizeof(arr[0]);
	int a=0,b=len;
	printf("4,6,10,11,13,16,19,22,35,45,57,66,73,78,83,87,89,95,102,110,124,127,129,141,161,189\n");
	printf("the number to search:");
	scanf("%d",&n);
	while(1){
		if(count>len){
			printf("j=0\n");
			break;
		}
		if(n==arr[(a+b)/2]){
			printf("%d\n",(a+b)/2);
			count++;
			break;
		}
		else if(n>arr[(a+b)/2]){
			a=(a+b)/2;
			count++;
			continue;
		}
		else{
			b=(a+b)/2;
			count++;
			continue;
		}
		
	}
}
