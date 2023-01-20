#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n;
int map[501][501] = { 0, };
int dp[500][500];

int dfs(int x, int y) {
	
	if (x == m - 1 && y == n - 1) {
		return 1;
	}
	if (dp[x][y] == -1) {	//처음 방문이면
		
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];

			if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n)
				continue;
			if (map[x][y] <= map[nextx][nexty])
				continue;

			dp[x][y] += dfs(nextx, nexty);
		}
	}
	return dp[x][y];
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			dp[i][j] = -1;
		}
	cout << dfs(0, 0);
}