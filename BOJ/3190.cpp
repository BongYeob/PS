#include <iostream>
#include <vector>

using namespace std;

int n;
int map[101][101] = { 0, };
vector<pair<int, int>> q;
vector<pair<int, char>> change;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool check(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > n)
		return false;
	for (int i = 0; i < q.size(); i++) {
		if (x == q[i].first && y == q[i].second)
			return false;
	}
	return true;
}

int main() {
	cin >> n;
	int apples;
	cin >> apples;
	for (int i = 0; i < apples; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}

	int changes;
	cin >> changes;
	for (int i = 0; i < changes; i++) {
		int when;
		char dir;
		cin >> when >> dir;
		change.push_back({ when, dir });
	}

	int time = 0;
	int cur_x = 1;
	int cur_y = 1;
	q.push_back({ cur_x, cur_y });

	int cur_dir = 0;	//0 오른쪽 1 아래 2 왼쪽 3 위
	int dir_time = 0;

	while (1) {
		time++;
		cur_x += dx[cur_dir];
		cur_y += dy[cur_dir];

		bool eat = false;
		if (map[cur_x][cur_y] == 1) {
			eat = true;
			map[cur_x][cur_y] = 0;
		}

		if (!check(cur_x, cur_y))	//false 면 멈춤
			break;

		q.push_back({ cur_x, cur_y });

		if (!eat)
			q.erase(q.begin());

		if(dir_time < changes)
			if (time == change[dir_time].first) {
				if (change[dir_time].second == 'D') {
					cur_dir++;
					cur_dir = cur_dir % 4;
				}
				else {
					cur_dir--;
					if (cur_dir < 0)
						cur_dir = 3;
				}
				dir_time++;
			}
	}

	cout << time;

	return 0;
}