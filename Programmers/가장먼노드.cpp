#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;
vector<int> graph[20001];
int dist[20001] = {0, };
bool visited[20001] = {false, };

void dijkstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty()) {

		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (visited[cur_node] == true)
			continue;
		visited[cur_node] = true;

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i];

			if (dist[next_node] > dist[cur_node] + 1) {
				dist[next_node] = dist[cur_node] + 1;
				pq.push({ dist[next_node], next_node });
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	
	for(auto i : edge){
	  int first = i[0];
	  int second = i[1];

	  graph[first].push_back(second);
	  graph[second].push_back(first);
	}
    
  for(int i=1; i<=n; i++){
	  dist[i] = INF;
  }
    
  dijkstra(1);
    
	int max = -1;

	for (int i=1; i<=n; i++){
	  if (max < dist[i])
			max = dist[i];
  }

	for (int i=1; i<=n; i++){
	  if (max == dist[i])
			answer++;
  }
    return answer;
}