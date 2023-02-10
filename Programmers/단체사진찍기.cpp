#include <string>
#include <vector>

using namespace std;

int answer{};
const char num[8] = { 'A','C', 'F','J','M','N','R','T' };
vector<char> arr;
bool visited[8] = {false,};

void check(vector<string>& data) {
	bool flag = true;
	for (auto i : data) {
		char p1 = i[0];
		char p2 = i[2];
		char oper = i[3];
		int num = i[4] - '0' + 1;
		int p1idx;
		int p2idx;
		
		for (int j = 0; j < 8; j++) {
			if (arr[j] == p1){
                p1idx = j;
            }
			if (arr[j] == p2){
                p2idx = j;
            }
		}

		int gap = abs(p1idx - p2idx);

		if (oper == '=') {
			if (gap != num){
                flag = false;
            }
		}
		if (oper == '<') {
			if (gap > num || gap == num){
                flag = false;
            }
		}
		if (oper == '>') {
			if (gap < num || gap == num){
                flag = false;
            }
		}
	}
	if (flag){
        answer++;
    }
}

void dfs(int size, vector<string>& data) {

	if (size == 8) {
		check(data);
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (visited[i] == false) {
			arr.push_back(num[i]);
			visited[i] = true;
			dfs(size + 1, data);
			arr.pop_back();
			visited[i] = false;
		}
	}
	return;
}

int solution(int n, vector<string> data) {
    answer=0;
    arr.clear();
    for(auto i : visited)
        i = false;
    
    dfs(0, data);    
    return answer;
}