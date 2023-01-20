#include <iostream>	//1707
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[20001];
int color[20001] = { 0, };	//012

bool bfs(int start) {

	queue<int> q;
	color[start] = 1;
	q.push(start);
	bool answer = true;


	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int cur_color = color[cur];

		for (int i = 0; i < graph[cur].size(); i++) {
			
			int next = graph[cur][i];

			if (color[next] != 0) {
				if (cur_color == color[next]) {
					answer = false;
					break;
				}
			}
			else {
				q.push(next);
				if (cur_color == 1)
					color[next] = 2;
				else
					color[next] = 1;
			}
		}

		if (answer == false)
			break;
	}

	return answer;
}

int main() {

	int num;
	cin >> num;

	int v, e;
	bool answer;

	while (num--) {

		cin >> v >> e;

		int start, end;
		answer = true;
		for (int i = 0; i < e; i++) {
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				answer = bfs(i);
				if (answer == false)
					break;
			}
		}

		if (answer == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		for (int i = 0; i <=v; i++) {
			graph[i].clear();
			color[i] = 0;
		}
	}
}