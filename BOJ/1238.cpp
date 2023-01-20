#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, x;
vector< pair<int, int> > graph[1001];
int dist[1001];

void dijkstra(int start, int finish) {	

	bool visited[1001] = { false, };
	priority_queue < pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>> > pq;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		if (visited[cur_node] == true)
			continue;

		visited[cur_node] = true;

		for (auto iter : graph[cur_node]) {

			int next_node = iter.second;
			int next_weight = iter.first;

			if (dist[next_node] > cur_dist + next_weight) {
				dist[next_node] = cur_dist + next_weight;
				pq.push({ dist[next_node], next_node });
			}
		}
		
		if (visited[finish] == true)
			break;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ w, b });
	}

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	int max = -1;

	for (int i = 1; i <= n; i++) {
		dijkstra(i, x);
		int temp = dist[x];
		dijkstra(x, i);
		int temp1 = dist[i];

		if (max < temp + temp1)
			max = temp + temp1;
	}

	cout << max;

	return 0;
}