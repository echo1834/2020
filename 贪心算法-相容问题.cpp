#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct{
    int s;      //开始
    int f;      //结束
    int i;      //活动的序号
}S;
void fsort(S a[],int n){  //根据结束时间进行非降序排序
    int i,j;
    S temp;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].f>a[j+1].f){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void ssort(S a[],int n){ //根据开始时间进行非降序排序
    int i,j;
    S temp;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].s>a[j+1].s){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void asort(S a[],int n){  //根据进行时间进行非降序排序
    int i,j;
    S temp;
    int t[n];
    for (int i=1; i<=n; i++) {
        t[i]=a[i].f-a[i].s;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(t[j]>t[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void Arrange(int n){
    S a[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i].s,&a[i].f);
        a[i].i=i;
    }
    fsort(a, n);
    bool flag[n+1];
    flag[1]=true;              //将第一个活动安排
    int pre=a[1].f;
    int num=1;
    for (int i=2;i<=n;i++) {
        if (a[i].s>=pre) {
            flag[i]=true;
            num++;//活动数+1
            pre=a[i].f;
        }
        else
            flag[i]=false;
    }
    printf("%d\n",num);        //最大相容活动数
    for (int i=1; i<=n; i++) {
        if (flag[i]) {
            printf("%d\t",a[i].i);  //活动序号
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);          //活动数
    Arrange(n);
    return 0;
}
