#include <stdio.h>
int n, m;/*����������ɫ��*/
int a[100][100];
int x[100];
int sum = 0;//��ɫ����
void input() {
	printf("������n����ɫ��m:\n");
	scanf("%d %d", &n, &m);
	printf("����ͼ���ڽӾ���:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
		printf("\n");
	}

}
int wap(int k) {
	for (int j = 1; j <= n; j++)
		if (a[k][j] && (x[j] == x[k]))return 0;
	return 1;
}
void backtrack(int t) {
	if (t > n)
	{
		sum++;
	}
	else
		for (int i = 1; i <= m; i++)
		{
			x[t] = i;
			if (wap(t) == 1)backtrack(t + 1);
			x[t] = 0;
		}
}

int colored()
{
	sum = 0;
	backtrack(1);
	return sum;
}
int main() {
	input();
	colored();
	if (sum > 0) {
		printf("��ɫ������Ϊ��%d\n", sum);
	}
	else
	{
	printf("NO\n");
	}
	return 0;
}
