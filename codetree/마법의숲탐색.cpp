#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[73][73] = {0,};
int visited[73][73] = {0,};
int r, c, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int g, gy;  //골렘 중심 좌표, 골렘 출구방향
bool out = false;

void clear_map(){
    for(int i=0; i<73; i++)
        for(int j=0; j<73; j++)
            map[i][j] =0;
}

void move(int curc, int golem, int d){
    g = 1;

    bool flag = true;
    while(1){
        
        if(flag == false){  //못 움직이면 map update
            if(g<=3){   //일부가 못들어옴
                out = true;
                break;
            }
            map[g][curc] = golem;
            map[g-1][curc] = golem;
            map[g][curc-1] = golem;
            map[g][curc+1] = golem;
            map[g+1][curc] = golem;
            map[g+dx[d]][curc+dy[d]] = golem + 1000;
            break;
        }

        if(g<=r && map[g+1][curc-1]==0 && map[g+2][curc]==0 && map[g+1][curc+1]==0){
            g++;    // 아래로 한칸
            if(g==r+1)
                flag = false;

        }
        else if(curc>=2 && map[g-1][curc-1]==0 && map[g][curc-2]==0 && map[g+1][curc-1]==0 && g<=r && map[g+1][curc-2]==0 && map[g+2][curc-1]==0){    //왼쪽 회전
            d += 3;
            d = d%4;
            curc -= 1;
            g++;
        }
        else if(curc<=c-3 && map[g-1][curc+1]==0 && map[g][curc+2]==0 && map[g+1][curc+1]==0 && g<=r && map[g+2][curc+1]==0 && map[g+1][curc+2]==0){    //오른쪽 회전
            d += 1;
            d = d%4;
            curc += 1;
            g++;
        }
        else{
            flag = false;
        }   
    }
    gy = curc;
}

int bfs(int x, int y){
    for(int i=0; i<73; i++)
        for(int j=0; j<73; j++)
            visited[i][j] = 0;

    int deep = x;
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        visited[curx][cury] = 1;
        int curg = (map[curx][cury] <= 1000) ? map[curx][cury] : map[curx][cury] - 1000;    //현재 골렘 종류
        if(deep < curx)
            deep = curx;
        q.pop();

        if(map[curx][cury] <= 1000){ // 현재 좌표가 출구가 아님
            for(int i=0; i<4; i++){
                int nx = curx+dx[i];
                int ny = cury+dy[i];
                if(nx<=r+2 && nx>=3 && ny>=0 && ny<=c-1)
                    if(visited[nx][ny] == 0 && (map[nx][ny] == curg || map[nx][ny] == curg+1000)){   // 방문하지 않았고, 현재 골렘 내부
                        q.push({nx, ny});
                    }
            }
        }
        else{   //현재 좌표가 출구임
            for(int i=0; i<4; i++){
                int nx = curx+dx[i];
                int ny = cury+dy[i];
                if(nx<=r+2 && nx>=3 && ny>=0 && ny<=c-1)
                    if(visited[nx][ny] == 0 && map[nx][ny] != 0){   // 방문하지 않았고, 0만 아니면 됨
                        q.push({nx, ny});
                    }
            }
        }
    }
    return deep-2;  // 실제값이랑 2 차이남
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>> r>> c>> k;

    int result = 0;
    for(int i=0; i<k; i++){ //1번씩 입력받음
        int startc, d;    //0:북, 1:동, 2:남, 3:서, d += 1000으로 저장
        cin>>startc>>d;
        startc = startc -1;
        int golem = i+1;  // 골렘 번호
        move(startc, golem, d);   // 아래로 움직이기
        if(out == true){
            clear_map();
            out = false;
        }
        else{
            result += bfs(g, gy);
        }

    }
    cout<<result;
    return 0;
}