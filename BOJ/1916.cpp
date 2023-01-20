#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
int start, finish;
vector < pair<int, int> > graph[1001];
bool visited[1001] = { false, };
int dist[1001] = { 0, };

void dijkstra(int start, int finish) {

	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair< int, int>> > pq;

	pq.push({ 0, start });
	dist[start] = 0;

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

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		graph[x].push_back({ w, y });
	}

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	cin >> start >> finish;

	dijkstra(start, finish);

	cout << dist[finish];
}