#include <iostream>
#include <vector>

using namespace std;


int map[21][21];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int dice[3][4] = { {0,5,0,0},{1,2,3,4},{0,6,0,0} };
int store[7] = { 0, };

void roll(int dir) {
	if (dir == 1) {
		int temp = dice[1][0];
		for (int i = 0; i < 3; i++)
			dice[1][i] = dice[1][i + 1];
		dice[1][3] = temp;
	}
	else if (dir == 2) {
		int temp = dice[1][3];
		for (int i = 3; i > 0; i--)
			dice[1][i] = dice[1][i - 1];
		dice[1][0] = temp;
	}
	else if (dir == 3) {
		int temp = dice[0][1];
		dice[0][1] = dice[1][3];
		dice[1][3] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = temp;
	}
	else if (dir == 4) {
		int temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[1][3];
		dice[1][3] = temp;
	}

	return;
}
 
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (k--) {
		int dir;
		cin >> dir;

		x += dx[dir];
		y += dy[dir];
		if (x < 0 || y < 0 || x >= n || y >= m) {
			x -= dx[dir];
			y -= dy[dir];
			continue;
		}

		roll(dir);

		int bottom = dice[1][1];
		if (map[x][y] == 0)
			map[x][y] = store[bottom];
		else {
			store[bottom] = map[x][y];
			map[x][y] = 0;
		}

		cout << store[dice[1][3]] << "\n";

	}

	return 0;
}