#include <iostream>

using namespace std;

int n, m, r, c, d;
int map[50][50];
//0 북쪽 1 동쪽 2 남쪽 3 서쪽
//왼 아래 오른 위
int dx[4][4] = { {0,1,0,-1}, {-1,0,1,0}, {0,-1,0,1}, {1,0,-1,0} }; 
int dy[4][4] = { {-1,0,1,0}, {0,-1,0,1}, {1,0,-1,0}, {0,1,0,-1} };
int cnt = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (1) {
		
		if (map[r][c] == 0) {
			cnt++;
			map[r][c] = 2;
		}

		if (map[r + dx[d][0]][c + dy[d][0]] == 0) {
			r += dx[d][0];
			c += dy[d][0];
			if (d)
				d = (d - 1) % 4;
			else d = 3;
			continue;
		}
		
		bool flag = false;
		for (int i = 0; i < 4; i++) {

			int nx = r + dx[d][0];
			int ny = c + dy[d][0];
			if (d)
				d = (d - 1) % 4;
			else d = 3;
			if (map[nx][ny] == 0) {
				r = nx;
				c = ny;
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		if (map[r + dx[d][1]][c + dy[d][1]]!=1) {
			r += dx[d][1];
			c += dy[d][1];
			continue;
		}

		break;
	}

	cout << cnt;

	return 0;
}