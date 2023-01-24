#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[8][8];
int copymap[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool check[8][8][8][8][8][8] = { false, };
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void bfs() {

	for (auto i : v)
		q.push(i);

	while (!q.empty()) {

		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];

			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
				continue;
			if (copymap[nextx][nexty] == 0) {
				copymap[nextx][nexty] = 2;
				q.push({ nextx,nexty });
			}
		}
	}
}

int count() {
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!copymap[i][j])
				cnt++;
		}
	return cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	
	int result = -1;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (map[x1][y1]==0) {
				map[x1][y1] = 1;	//벽세움 나중에 풀어줘야함
				for (int x2 = 0; x2 < n; x2++) {
					for (int y2 = 0; y2 < m; y2++) {
						if (map[x2][y2]==0) {
							map[x2][y2] = 1;
							for (int x3 = 0; x3 < n; x3++) {
								for (int y3 = 0; y3 < m; y3++) {
									if (check[x1][y1][x2][y2][x3][y3])
										continue;
									if (x1 == x2 && y1 == y2) 
										continue;
									if (x1 == x3 && y1 == y3) 
										continue;
									if (x2 == x3 && y2 == y3) 
										continue;
									if (map[x3][y3]==0) {
										map[x3][y3] = 1;
										memcpy(copymap, map, sizeof(map));
										bfs();
										int temp = count();
										if (result < temp)
											result = temp;
										map[x3][y3] = 0;
										check[x1][y1][x2][y2][x3][y3] = true;
									}
								}
							}
							map[x2][y2] = 0;
						}
					}
				}
				map[x1][y1] = 0;
			}
		}
	}

	cout << result;

	return 0;
}