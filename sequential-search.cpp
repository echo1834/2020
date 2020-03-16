#include<stdio.h>
int main() {
	int data[] = {4,6,10,11,13,16,19,22,35,45,57,66,73,78,83,87,89,95,102,110,124,127,129,141,161,189};
	int i, key;
	int flag = 0;
	printf("4,6,10,11,13,16,19,22,35,45,57,66,73,78,83,87,89,95,102,110,124,127,129,141,161,189\n");
	printf("the number to search:");
	scanf("%d", &key);
	int t=sizeof(data);
	for (i = 1; i < t; i++) {
		if (data[i] == key) {
			printf("j = %d", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("j=0");
}
