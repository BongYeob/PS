#include <iostream>

using namespace std;

int row, col, result;
char map[20][20];
int check[26];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, int z){
    if(result < z)
        result = z;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || nx>= row || ny<0 || ny>=col)
            continue;

        int c = map[nx][ny] - 'A';
        if(check[c] == 1)
            continue;

        check[c] = 1;
        dfs(nx,ny,z+1);
        check[c] = 0;
    }
}

	int main(){
	cin >> row >> col;
	
	for(int i=0; i<row; i++)
	  for(int j=0; j<col; j++){
	      char c;
	      cin >> c;
	      map[i][j] = c;
	  }

	check[map[0][0] - 'A'] = 1;
	dfs(0,0,1);

	cout << result;
	return 0;
}