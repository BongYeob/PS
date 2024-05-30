#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k, m;
int map[5][5];
int copy_map[5][5];
int wall[300];
int cur_w = 0;
int score1 = -1;
int fix_xy[3] = {-1, -1, -1};    //유물 1차 획득 좌표 정보 몇번 회전, x, y
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[5][5] = {false, };
pair<int, int> r[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

void update_xy(int temp_score, int rotate_cnt, int x, int y){
    if(score1 < temp_score){
        score1 = temp_score;
        fix_xy[0] = rotate_cnt;  //몇 도 회전했는지
        fix_xy[1] = x;
        fix_xy[2] = y;
    }
    else if(score1 == temp_score){
        if(rotate_cnt < fix_xy[0]){
            fix_xy[0] = rotate_cnt;
            fix_xy[1] = x;
            fix_xy[2] = y;
        }
        else if(rotate_cnt == fix_xy[0]){// 열 그다음 행
            if(y < fix_xy[2]){
                fix_xy[1] = x;
                fix_xy[2] = y;
            }
            else if(y == fix_xy[2]){
                if(x < fix_xy[1])
                    fix_xy[1] = x;
            }
        }
    }
}

void rotate_map(int x, int y, int cnt_r){

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            copy_map[i][j] = map[i][j];

    int buffer[8];
    for(int i=0; i<8; i++)
        buffer[i] = copy_map[x + r[i].first][y + r[i].second];

    int dr = (cnt_r + 1) * 2;
    for(int i=0; i<8; i++){
        int nr = (dr + i) % 8;
        copy_map[x + r[nr].first][y + r[nr].second] = buffer[i];
    }
}

int bfs(int x, int y, int mode){
    if (visited[x][y] == true)
        return 0;
    
    int cnt =1;
    visited[x][y] = true;
    int cur_num = copy_map[x][y];
    vector<pair<int, int>> temp_scored;

    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        temp_scored.push_back({curx, cury});
        
        for(int i=0; i<4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx>=0 && nx<5 && ny>=0 && ny<5){
                if(copy_map[nx][ny] == cur_num && visited[nx][ny] == false){
                    q.push({nx, ny});
                    cnt+=1;
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if(cnt >= 3){
        if(mode == 1)   //0으로 바꿔서 bfs할 때
            for(auto i : temp_scored)
                copy_map[i.first][i.second] = 0;
        return cnt;
    }

    return 0;
}

void select_xy(int x, int y){
    //1. 90 180 270 회전 2. bfs로 1차 점수 계산
    for(int i=0; i<3; i++){
        rotate_map(x, y, i);
        int temp_score = 0;

        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                visited[j][k] = false;

        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                temp_score += bfs(j, k, 0);
        //score1 update
        update_xy(temp_score, i, x, y);
    }
}

void fill_map(){
    for(int i=0; i<5; i++){
        for(int j=4; j>=0; j--)
            if(copy_map[j][i] == 0)
                copy_map[j][i] = wall[cur_w++];
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> k>> m;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>map[i][j];
    for(int i=0; i<m; i++)
        cin>>wall[i];
    
    int turn =0;
    while(1){
        turn += 1;

        score1 = -1;
        for(int i=1; i<=3; i++) // 1차 획득할 좌표 정하기
            for(int j=1; j<=3; j++)
                select_xy(i, j);
        if(score1 == 0) //더이상 유물 존재x
            break;

        //적용, 0으로 만들기
        rotate_map(fix_xy[1], fix_xy[2], fix_xy[0]);

        int result = 0;
        while(1){
            int cur_result =0;

            for(int i=0; i<5; i++)
                for(int j=0; j<5; j++)
                    visited[i][j] = false;

            for(int i=0; i<5; i++)
                for(int j=0; j<5; j++){
                    cur_result += bfs(i, j, 1);
                }
                    
            if(cur_result == 0)
                break;
            result += cur_result;
            fill_map();
        }
        cout<<result<<" ";

        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                map[i][j] = copy_map[i][j];
        
        if(turn == k)
            break;
    }
}