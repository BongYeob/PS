#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[10][10];
int n, m;

pair<int, int> red;
pair<int, int> blue;
pair<int, int> hole;

typedef struct cur {
	int redx;
	int redy;
	int bluex;
	int bluey;
	int level;
}cur;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[10][10][10][10] = { false, };

int bfs() {
	
	visited[red.first][red.second][blue.first][blue.second] = true;

	queue<cur> q;
	q.push({ red.first, red.second, blue.first, blue.second, 0 });


	while (!q.empty()) {
		cur now = q.front();
		q.pop();
		
		//red가 hole에 빠지면
		if (now.redx == hole.first && now.redy == hole.second)
			return now.level;

		for (int i = 0; i < 4; i++) {

			int cur_redx = now.redx;
			int cur_redy = now.redy;
			int cur_bluex = now.bluex;
			int cur_bluey = now.bluey;

			int cnt_red = 0;
			int cnt_blue = 0;

			//red 움직임
			while (map[cur_redx + dx[i]][cur_redy + dy[i]] != '#' && map[cur_redx][cur_redy] != 'O') {
				cur_redx += dx[i];
				cur_redy += dy[i];
				cnt_red++;
			}

			//blue 움직임
			while (map[cur_bluex + dx[i]][cur_bluey + dy[i]] != '#' && map[cur_bluex][cur_bluey] != 'O') {
				cur_bluex += dx[i];
				cur_bluey += dy[i];
				cnt_blue++;
			}
			
			//blue가 hole에 빠지면
			if (cur_bluex == hole.first && cur_bluey == hole.second)
				continue;

			//안 빠지니까 위치 조정
			if (cur_redx == cur_bluex && cur_redy == cur_bluey) {
				if (cnt_red > cnt_blue) {
					cur_redx -= dx[i];
					cur_redy -= dy[i];
					cnt_red--;
				}
				else {
					cur_bluex -= dx[i];
					cur_bluey -= dy[i];
					cnt_blue--;
				}
			}

			//전에 방문 넘김
			if (visited[cur_redx][cur_redy][cur_bluex][cur_bluey])
				continue;

			//10번 이하로 움직였으면
			if (now.level < 10) {
				visited[cur_redx][cur_redy][cur_bluex][cur_bluey] = true;
				q.push({ cur_redx, cur_redy, cur_bluex, cur_bluey, now.level + 1 });
			}


		}
	}
	

	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> n >> m;

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 'R') {
				red.first = i;
				red.second = j;
			}
			else if (temp == 'B') {
				blue.first = i;
				blue.second = j;
			}
			else if (temp == 'O') {
				hole.first = i;
				hole.second = j;
			}
		}
	
	cout << bfs();

	return 0;
}