#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m, n, k;
	cin >> n >> m >> k;
	vector<vector<bool>> map(n+4,vector<bool>(4+n,true));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = 0; j < 3; j++) {
			for (int q = 0; q < 3; q++) {
				map[x + j][y + q] = false;
			}
		}
		map[x-1][y] = false;
		map[x][y-1] = false;
		map[x+3][y] = false;
		map[x][y+3] = false;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x -= 1, y -= 1;
		for (int j = 0; j < 5; j++) {
			for (int q = 0; q < 5; q++) {
				map[x + j][y + q] = false;
			}
		}
	}
	int dark = 0;
	for (int i = 2; i < n+2; i++) {
		for (int j = 2; j < n+2; j++) {
			if (map[i][j]) dark++;
		}
	}
	cout << dark << endl;
	return 0;
}
