#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int map[25][25] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> result;

void bfs(int x, int y) {

	int aptcnt = 1;

	map[x][y] = 0;	//시작 지점 visited 
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && map[next_x][next_y] == 1) {
				map[next_x][next_y] = 0;
				aptcnt++;
				q.push({ next_x, next_y });
			}
		}
	}

	result.push_back(aptcnt);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j=0; j<n; j++){
			map[i][j] = s[j]-'0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				bfs(i, j);
			}	
		}
	}
	
	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (auto i : result)
		cout << i << "\n";

	return 0;
}