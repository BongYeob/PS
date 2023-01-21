#include <iostream>

using namespace std;

int n, m;
int map[500][500];
bool visited[500][500] = { false, };

int result = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int sum = 0;

int dfs(int x, int y, int level) {
	if (level == 3) {

		if (result < sum)
			result = sum;
		
		return 0;
	}

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= n || y + dy[i] >= m) {
			continue;
		}
		if (visited[x + dx[i]][y + dy[i]])
			continue;

		x += dx[i];
		y += dy[i];
		visited[x][y] = true;
		sum += map[x][y];
		dfs(x, y, level + 1);
		sum -= map[x][y];
		visited[x][y] = false;
		x -= dx[i];
		y -= dy[i];
	}

	return 0;
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			sum = map[i][j];
			visited[i][j] = true;
			dfs(i, j, 0);
			visited[i][j] = false;
			
		}

	int temp, temp1;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			temp1 = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i + 2][j + 1];

			if (result < temp)
				result = temp;
			if (result < temp1)
				result = temp1;
		}
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			temp1 = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];

			if (result < temp)
				result = temp;
			if (result < temp1)
				result = temp1;
		}
	}

	cout << result;			

	return 0;
}