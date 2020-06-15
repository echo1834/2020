#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int max1 = 10000;
double min1 = 1000;
double X[max1], r[max1];// 分别为每个圆心的横坐标 ，每个圆的半径 ，
double small[max1]; // 最小圆排列的半径顺序
int n;
double center(int t) {
	double temp = 0;
	for (int i = 1; i < t; ++i) {
		double res = X[i] + 2.0 * sqrt(r[t] * r[i]); //. 目标圆T有可能能够和排在它之前的任意一个圆相切，因此需要以一判断取最大值
		temp = max(temp, res);
	}
	return temp;
}

void len() {
	double min2 = 0, max2 = 0; // 计算最优圆排列的最左端 和 最右端
	for (int i = 1; i <= n ; ++i) {
		if (X[i] - r[i] < min2) min2 = X[i] - r[i];
		if (X[i] + r[i] > max2) max2 = X[i] + r[i];
	}
	if (max2 - min2 < min1) {
		min1 = max2 - min2; // 更新最小圆排列
		for (int i = 1; i <= n ; ++i) {
			small[i] = r[i];
		}
	}
}


void dfs(int t) {
	if (t == n + 1) {
		len();
	}     else {
		for (int i = t; i <= n; ++i) {
			swap(r[t], r[i]);//构造全排列
			double X_t = center(t);
			if (X_t + r[t] + r[1] < min1) { 
				X[t] = X_t;
				dfs(t + 1);
			}
			swap(r[t], r[i]); //恢复现场 
		}
	}
}


int main() {
	cout << "please enter the numbers of  circle:";
	cin >> n;
	cout << "please enter the circle:";
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
	}
	for (int i = 1; i <= n; ++i) {
		cout <<"the "<< i << " cirlce ：" << r[i] << endl;
	}
	dfs(1);
	cout << "the length is：" << min1 << endl;
	cout << "the circle list：";
	for (int i = 1; i <= n; ++i) {
		cout << small[i] << " ";
	}
	return 0;
}
