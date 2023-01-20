#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[10001];

bool bfs(int factory1, int factory2, int weight) {
	bool visited[10001] = { false, };
	queue<int> q;
	bool answer = false;

	q.push(factory1);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (visited[cur] == true)
			continue;
		visited[cur] = true;

		for (auto i : graph[cur]) {
			if (i.first >= weight) {
				q.push(i.second);
			}
		}

		if (visited[factory2] == true) {
			answer = true;
			break;
		}
	}
	return answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int start, finish, w;
	long int min = 1000000001, max = 0;

	while (m--) {
		cin >> start >> finish >> w;
		if (max < w)
			max = w;
		if (min > w)
			min = w;
		graph[start].push_back({ w, finish });
		graph[finish].push_back({ w, start });
	}
	
	int factory1, factory2;
	cin >> factory1 >> factory2;
	
	long int answer;

	while (min <= max) {
		long int mid = (min + max) / 2;
		if (bfs(factory1, factory2, mid) == false)
			max = mid - 1;
		else {
			answer = mid;
			min = mid + 1;
		}
	}
	cout << answer;
}