#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[21][21];
int copymap[21][21];

int n;
int dir[4];

int result = -1;

void move(int direction) {
	//위로 올렸을 때
	if (direction == 1) {
		//가로 n줄
		for (int i = 0; i < n; i++) {
			queue<int> q;

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[j][i] == 0)
					continue;

				if (q.empty())
					q.push(copymap[j][i]);
				else {
					if (q.front() != copymap[j][i]) {
						copymap[cnt][i] = q.front();
						q.pop();
						cnt++;
						q.push(copymap[j][i]);
					}
					else {
						copymap[cnt][i] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			if (!q.empty()) {
				copymap[cnt++][i] = q.front();
				q.pop();
			}

			for (int j = cnt; j < n; j++)
				copymap[j][i] = 0;

		}
	}
	//아래로
	else if (direction == 2) {
		//가로 n줄
		for (int i = 0; i < n; i++) {
			queue<int> q;

			int cnt = 0;
			for (int j = n-1; j >= 0; j--) {
				if (copymap[j][i] == 0)
					continue;

				if (q.empty())
					q.push(copymap[j][i]);
				else {
					if (q.front() != copymap[j][i]) {
						copymap[n - 1 - cnt][i] = q.front();
						q.pop();
						cnt++;
						q.push(copymap[j][i]);
					}
					else {
						copymap[n - 1 - cnt][i] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			if (!q.empty()) {
				copymap[n - 1 - cnt][i] = q.front();
				cnt++;
				q.pop();
			}

			for (int j = 0; j < n - cnt; j++)
				copymap[j][i] = 0;

		}
	}
	//왼쪽
	else if (direction == 3) {
		//세로 n줄
		for (int i = 0; i < n; i++) {
			queue<int> q;

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[i][j] == 0)
					continue;
				
				if (q.empty())
					q.push(copymap[i][j]);
				else{
					if (q.front() != copymap[i][j]) {
						copymap[i][cnt] = q.front();
						q.pop();
						cnt++;
						q.push(copymap[i][j]);
					}
					else {
						copymap[i][cnt] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			if (!q.empty()) {
				copymap[i][cnt++] = q.front();
				q.pop();
			}
				
			for (int j = cnt; j < n; j++)
				copymap[i][j] = 0;

		}
	}
	//오른쪽
	else if (direction == 4) {
		//세로 n줄
		for (int i = 0; i < n; i++) {
			queue<int> q;

			int cnt = 0;
			for (int j = n-1; j >= 0; j--) {
				if (copymap[i][j] == 0)
					continue;

				if (q.empty())
					q.push(copymap[i][j]);
				else {
					if (q.front() != copymap[i][j]) {
						copymap[i][n - 1 - cnt] = q.front();
						q.pop();
						cnt++;
						q.push(copymap[i][j]);
					}
					else {
						copymap[i][n - 1 - cnt] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			if (!q.empty()) {
				copymap[i][n - 1 - cnt] = q.front();
				cnt++;
				q.pop();
			}

			for (int j = 0; j < n - cnt; j++)
				copymap[i][j] = 0;

		}
	}
}


void f(int level) {
	if (level == 5) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				copymap[i][j] = map[i][j];

		for (int i = 0; i < 5; i++)
			move(dir[i]);

		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (result < copymap[i][j])
					result = copymap[i][j];
			}

		return;

	}
	for (int i = 1; i <= 4; i++) {
		dir[level] = i;
		f(level + 1);
	}
	return;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << copymap[i][j]<<" ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	result = -1;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	f(0);
	cout << result;

	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		copymap[i][j] = map[i][j];

	//move(2);
	//print();
	//cout << endl;
	
	return 0;
}