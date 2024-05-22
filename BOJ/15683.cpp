#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[8][8];  //7은 cctv로 본 구역
int copymap[8][8];
vector<pair<int, int>> cctv[6]; //x, y
int total_level=0;
int result = 100;
vector<int> order;   //방향

void fillup(int x, int y){
    for(int j = x; j>=0; j--){
            if(copymap[j][y] == 6)
                break;
            if(copymap[j][y] == 0)
                copymap[j][y] = 7;
        }
}

void filldown(int x, int y){
    for(int j=x; j<n; j++){
            if(copymap[j][y] == 6)
                break;
            if(copymap[j][y] == 0)
                copymap[j][y] = 7;
        }
}

void fillleft(int x, int y){
    for(int j=y; j>=0; j--){
            if(copymap[x][j] == 6)
                break;
            if(copymap[x][j] == 0)
                copymap[x][j] = 7;
        }
}

void fillright(int x, int y){
    for(int j=y; j<m; j++){
            if(copymap[x][j] == 6)
                break;
            if(copymap[x][j] == 0)
                copymap[x][j] = 7;
        }
}

void fillcopymap(int x, int y, int type, int dir){
    if(type == 1){
        if(dir == 0)
            fillup(x, y);
        else if(dir == 1)
            fillright(x, y);
        else if(dir == 2)
            filldown(x, y);
        else
            fillleft(x, y);
    }
    else if(type == 2){
        if(dir == 0){
            fillleft(x, y);
            fillright(x, y);
        }
        else if(dir == 2){
            fillup(x, y);
            filldown(x, y);
        }
    }
    else if(type == 3){
        if(dir == 0){
            fillup(x, y);
            fillright(x, y);
        }
        else if(dir == 1){
            fillright(x, y);
            filldown(x, y);
        }
        else if(dir == 2){
            filldown(x, y);
            fillleft(x, y);
        }
        else{
            fillleft(x, y);
            fillup(x, y);
        }
    }
    else if(type == 4){
        if(dir == 0){
            fillup(x, y);
            fillleft(x, y);
            fillright(x, y);
        }
        else if(dir == 1){
            fillup(x, y);
            filldown(x, y);
            fillright(x, y);
        }
        else if(dir == 2){
            fillleft(x, y);
            filldown(x, y);
            fillright(x, y);
        }
        else{
            fillleft(x, y);
            filldown(x, y);
            fillup(x, y);
        }
    }
}

void makecopymap(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            copymap[i][j] = map[i][j];
}

int count4(){
    int cnt =0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(copymap[i][j]==0)
                cnt++;
    return cnt;
}

void dfs(int level){
    //make order, 0: 북, 1: 동, 2: 남, 3: 서
    if(level == total_level){   //다 만들어졌으니까 map 적용하고 count
        makecopymap();

        int cctv_cnt = 0;
        for(int i=1; i<=4; i++){
            for(auto p : cctv[i]){
                // type == 2고 order[cctv_cnt] == 1 or 3이면 return;
                if(i==2 && (order[cctv_cnt] == 1 || order[cctv_cnt] == 3))
                    return;
                fillcopymap(p.first, p.second, i, order[cctv_cnt]);
                cctv_cnt += 1;
            }
        }

        int temp_result = count4();
        if(result > temp_result)
            result = temp_result;
        return;
    }

    for(int i=0; i<4; i++){
        order.push_back(i); //2번 cctv는 01이 좌우, 23이 상하
        dfs(level+1);
        order.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>> n>> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cctv[map[i][j]].push_back({i, j});
                if(map[i][j] != 5)
                    total_level += 1;
            }
        }
    
    //5는 돌릴 필요 없으니까 미리 처리
    for(auto i : cctv[5]){
        int x = i.first;
        int y = i.second;
        //윗방향
        for(int j = x; j>=0; j--){
            if(map[j][y] == 6)
                break;
            if(map[j][y] == 0)
                map[j][y] = 7;
        }
        //아래
        for(int j=x; j<n; j++){
            if(map[j][y] == 6)
                break;
            if(map[j][y] == 0)
                map[j][y] = 7;
        }
        //왼쪽
        for(int j=y; j>=0; j--){
            if(map[x][j] == 6)
                break;
            if(map[x][j] == 0)
                map[x][j] = 7;
        }
        //오른쪽
        for(int j=y; j<m; j++){
            if(map[x][j] == 6)
                break;
            if(map[x][j] == 0)
                map[x][j] = 7;
        }
    }
    
    dfs(0);
    cout<<result;
}