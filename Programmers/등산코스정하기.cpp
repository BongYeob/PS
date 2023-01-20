#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[50001];
bool bgates[50001] = { false, };
bool bsummits[50001] = { false, };
int dist[50001] = {0, };

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool visited[50001] = { false, };

	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty()) {

		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (visited[cur_node])
			continue;
		visited[cur_node] = true;

		for (auto next : graph[cur_node]) {
			int next_node = next.second;
			int weight = next.first;

			if ( dist[next_node] > max(dist[cur_node], weight) ) {
				dist[next_node] = max(dist[cur_node], weight);
				pq.push({ dist[next_node], next_node });
			}
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
    
  for(auto i : gates)
      bgates[i] = true;
  
  for(auto i : summits)
      bsummits[i] = true;
  
  for(auto i : paths){
      
    int start = i[0];
    int finish = i[1];
	  int w = i[2];
      
	  if (bgates[finish] || bsummits[start])
			graph[finish].push_back({ w, start });
		else if (bgates[start] || bsummits[finish])
			graph[start].push_back({ w, finish });
		else {
			graph[start].push_back({ w, finish });
			graph[finish].push_back({ w, start });
		}
  }
  
  for (int i = 0; i <= n; i++)
		dist[i] = INF;
  
  for (auto i : gates) {
		dijkstra(i);
	}
    
  int min = INF;
	int san = INF;

	for (auto i : summits) {
		if (dist[i] < min && dist[i]) {  //dist[gate] 는 0이므로 제외
			min = dist[i];
			san = i;
		}
		if (dist[i] == min && dist[i]) {
			if (san > i) {
				san = i;
			}
		}
	}
    
	answer.push_back(san);
  answer.push_back(min);
    
  return answer;
}