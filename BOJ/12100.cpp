#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


int map[20][20];
int copymap[20][20];
int dir[5];
int result = -1;
int n;

queue<int> q;

void move(int direction) {
	if (direction == 1) {	//왼쪽

		for (int i = 0; i < n; i++) {

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[i][j] == 0)
					continue;
				
				if (q.empty())
					q.push(copymap[i][j]);
				else {
					if (q.front() != copymap[i][j]) {
						q.push(copymap[i][j]);
						copymap[i][cnt] = q.front();
						q.pop();
						cnt++;
					}
					else {
						copymap[i][cnt] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			while (!q.empty()) {
				copymap[i][cnt] = q.front();
				q.pop();
				cnt++;
			}
			for (int j = cnt; j < n; j++)
				copymap[i][j] = 0;
		}
	}
	else if (direction == 2) {	//위쪽

		for (int i = 0; i < n; i++) {

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[j][i] == 0)
					continue;

				if (q.empty())
					q.push(copymap[j][i]);
				else {
					if (q.front() != copymap[j][i]) {
						q.push(copymap[j][i]);
						copymap[cnt][i] = q.front();
						q.pop();
						cnt++;
					}
					else {
						copymap[cnt][i] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			while (!q.empty()) {
				copymap[cnt][i] = q.front();
				q.pop();
				cnt++;
			}
			for (int j = cnt; j < n; j++)
				copymap[j][i] = 0;
		}
	}
	else if (direction == 3) {	//오른쪽

		for (int i = 0; i < n; i++) {

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[i][n-1-j] == 0)
					continue;

				if (q.empty())
					q.push(copymap[i][n-1-j]);
				else {
					if (q.front() != copymap[i][n-1-j]) {
						q.push(copymap[i][n-1-j]);
						copymap[i][n-1-cnt] = q.front();
						q.pop();
						cnt++;
					}
					else {
						copymap[i][n-1-cnt] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			while (!q.empty()) {
				copymap[i][n-1-cnt] = q.front();
				q.pop();
				cnt++;
			}
			for (int j = cnt; j < n; j++)
				copymap[i][n-1-j] = 0;
		}
	}
	else if (direction == 4) {	//아래쪽

		for (int i = 0; i < n; i++) {

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (copymap[n-1-j][i] == 0)
					continue;

				if (q.empty())
					q.push(copymap[n-1-j][i]);
				else {
					if (q.front() != copymap[n-1-j][i]) {
						q.push(copymap[n-1-j][i]);
						copymap[n-1-cnt][i] = q.front();
						q.pop();
						cnt++;
					}
					else {
						copymap[n-1-cnt][i] = q.front() * 2;
						q.pop();
						cnt++;
					}
				}
			}
			while (!q.empty()) {
				copymap[n-1-cnt][i] = q.front();
				q.pop();
				cnt++;
			}
			for (int j = cnt; j < n; j++)
				copymap[n-1-j][i] = 0;
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << copymap[i][j] << " ";
		cout << endl;
	}
	return;
}

void f(int level) {
	if (level == 5) {

		memcpy(copymap, map, sizeof(map));

		for (auto i : dir)
			move(i);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (result < copymap[i][j])
					result = copymap[i][j];
		return;
	}

	for (int i = 1; i <= 4; i++) {
		dir[level] = i;
		f(level + 1);
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	f(0);
	cout << result;
	
	return 0;
}