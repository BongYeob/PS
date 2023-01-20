#include <iostream> 
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

vector< pair<int, int> > graph[20001];
int dist[20001];

void dijkstra(int v, int start) {	//1이 아닐수도 있음
	priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>> > pq;
	//fisrt = 간선 가중치 second = 도달 정점

	bool visited[20001] = { false, };

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		
		int w = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur] == true)
			continue;

		visited[cur] = true;

		for (int i = 0; i < graph[cur].size(); i++) {
			if (dist[graph[cur][i].second] > dist[cur] + graph[cur][i].first) {
				dist[graph[cur][i].second] = dist[cur] + graph[cur][i].first;
				pq.push({ dist[graph[cur][i].second], graph[cur][i].second });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int begin;
	cin >> begin;

	for (int i = 0; i <= v; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < e; i++) {
		int start, end, w;
		bool check = false;

		cin >> start >> end >> w;

		for (int j = 0; j < graph[start].size(); j++) {
			if (graph[start][j].second == end) {
				if (graph[start][j].first > w)
					graph[start][j].first = w;
				check = true;
			}
		}
		if (check == false)
			graph[start].push_back({ w, end });	//가중치, 도착 정점
	}

	dijkstra(v, begin);

	for (int i = 1; i <= v; i++) {

		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}