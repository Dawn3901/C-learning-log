#include<iostream>
using namespace std;

double max(double a, double b) {
	return a > b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int max(int a) {
	return a;
}

int dup(int n) {
	if (n == 0 || n == 1) return 0;
	if (n == 2) return 1;
	if (n > 2) return (n-1)*(dup(n - 1) + dup(n - 2));
}

double P(int n) {
	double p = 1.0;
	for (int i = 0; i < n; ++i) {
		p *= (1.0 - (float)i / 365);
	}
	return 1 - p;
}

void problem() {
	int b, c;
	for (b = 1; b <= 6; b++) {
		for (c = 1; c <= 6; c++) {
			if (b * b - 4 * c > 0) cout << "+";
			if (b * b - 4 * c == 0) cout << "0";
			if (b * b - 4 * c < 0) cout << "-";
		}
		cout << endl;
	}
}



int main() {
	cout << "输入人数:" << endl;
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		else printf("存在两人相同生日的概率为%f%%\n", P(n) * 100);
	}
	problem();
	return 0;
}
