#include <iostream>
#include <vector>
#include <queue>

#define INF 87654321

using namespace std;

int n, e;
vector< pair<int, int> > graph[801];
int dist[801];

int dijkstra(int start, int finish) {

	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
	bool visited[801] = { false, };

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;

	pq.push({ 0, start });

	while (!pq.empty()) {

		auto cur = pq.top();
		int cur_dist = cur.first;
		int cur_node = cur.second;
		pq.pop();

		if (visited[cur_node] == true)
			continue;

		visited[cur_node] = true;

		for (auto i : graph[cur_node]) {

			int cur_to_next = i.first;
			int next_node = i.second;

			if (dist[next_node] > cur_dist + cur_to_next) {
				dist[next_node] = cur_dist + cur_to_next;
				pq.push({ dist[next_node], next_node });
			}
		}

		if (visited[finish] == true)
			break;
	}

	return dist[finish];
}

int find_way(int start, int finish, int v1, int v2) {

	int s1 = dijkstra(start, v1);	
	int s2 = dijkstra(start, v2);	
	int vtov = dijkstra(v1, v2);
	int f1 = dijkstra(v1, finish);
	int f2 = dijkstra(v2, finish);

	int way1 = s1 + vtov + f2;
	int way2 = s2 + vtov + f1;

	if ((way1 >= INF) && (way2 >= INF))
		return -1;
	else {
		if (way1 > way2)
			return way2;
		return way1;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	int v1, v2;
	cin >> v1 >> v2;

	cout << find_way(1, n, v1, v2);
}