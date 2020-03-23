#include<stdio.h>
int MergeArray(int a[], int low, int mid, int high, int flag[])  
{  
    int i = low;
	int j = mid + 1;  
    int m = mid;
	int n = high;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            flag[k++] = a[i++];  
        else  
            flag[k++] = a[j++];  
    }  
      
    while (i <= m)  
        flag[k++] = a[i++];  
      
    while (j <= n)  
        flag[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[low + i] = flag[i];  
}  

int MergeSort(int a[], int low, int high, int flag[])  
{  
    if (low < high)  
    {  
        int mid = (low + high) / 2;  
        MergeSort(a, low, mid, flag);     
        MergeSort(a, mid + 1, high, flag); 
        MergeArray(a, low, mid, high, flag); 
    }  
}  

int main(){
    int a[100];
    int t;
    int b[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
    	scanf("%d",&a[i]);
	}
	MergeSort(a,0,t,b);
	for(int i=0;i<t;i++){
    	printf("%d ",b[i]);
	}
}
