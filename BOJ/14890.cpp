#include <iostream>
#include <vector>

using namespace std;

int n, l;
int map[100][100];
int cnt = 0;

vector<int> test;
vector<int> test1;

void check(vector<int> test) {
	//줄어드는거 올라가는거 확인
	//내려가는거 하고 뒤집어서 하면 됨

	bool slide[100] = { false, };
	int cur_h = test[0];
	int i = 0;
	while(1) {
		if (i >= n)
			break;
		if (test[i] == cur_h) {
			i++;
			continue;
		}
		if (cur_h - test[i] > 1)
			return;
		if (cur_h - test[i] < 0) {	// 커지면 아래에서 할거임
			cur_h = test[i];
			i++;
			continue;
		}
		//cur_h - test[i] == 1
		if (i + l > n)
			return;

		cur_h--;
		for (int j = 0; j < l; j++) {
			if (cur_h != test[i + j])
				return;
			else
				slide[i + j] = true;
		}
		i += l;
	}

	cur_h = test[n - 1];
	i = n - 1;
	while (1) {
		if (i < 0)
			break;
		if (test[i] == cur_h) {
			i--;
			continue;
		}
		if (cur_h - test[i] > 1)
			return;
		if (cur_h - test[i] < 0) {	// 커진거 위에서 함
			cur_h = test[i];
			i--;
			continue;
		}
		//cur_h - test[i] == 1
		if (i - l < -1)
			return;

		cur_h--;
		for (int j = 0; j < l; j++) {
			if (cur_h != test[i - j] || slide[i - j])
				return;
		}
		i -= l;
	}
	cnt++;

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		vector<int>().swap(test);
		vector<int>().swap(test1);
		for (int j = 0; j < n; j++) {
			test.push_back(map[i][j]);
			test1.push_back(map[j][i]);
		}
		check(test);
		check(test1);
	}

	cout << cnt;

	return 0;
}