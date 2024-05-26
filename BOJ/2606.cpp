#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> com[101];
bool visited[101] = {false, };
int cnt =-1;

void bfs(){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(visited[cur] == false){
            for(auto i : com[cur])
                q.push(i);
            cnt +=1;
            visited[cur] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int s, f;
        cin>>s>>f;
        com[s].push_back(f);
        com[f].push_back(s);
    }

    bfs();
    cout<<cnt;
  
}