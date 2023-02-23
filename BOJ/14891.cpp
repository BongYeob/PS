#include <iostream>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<int> v4;

void rotate(int gear, int dir) {
	if (dir == 1) {
		if (gear == 1) {
			int temp = v1[7];
			v1.erase(v1.end() - 1);
			v1.insert(v1.begin(), temp);
		}
		else if (gear == 2) {
			int temp = v2[7];
			v2.erase(v2.end() - 1);
			v2.insert(v2.begin(), temp);
		}
		else if (gear == 3) {
			int temp = v3[7];
			v3.erase(v3.end() - 1);
			v3.insert(v3.begin(), temp);
		}
		else if (gear == 4) {
			int temp = v4[7];
			v4.erase(v4.end() - 1);
			v4.insert(v4.begin(), temp);
		}
	}
	else if (dir == -1) {
		if (gear == 1) {
			v1.push_back(v1[0]);
			v1.erase(v1.begin());
		}
		else if (gear == 2) {
			v2.push_back(v2[0]);
			v2.erase(v2.begin());
		}
		if (gear == 3) {
			v3.push_back(v3[0]);
			v3.erase(v3.begin());
		}
		if (gear == 4) {
			v4.push_back(v4[0]);
			v4.erase(v4.begin());
		}
	}
}

void move(int gear, int dir) {
	int moved[5] = { 0, };
	int ndir[5] = { 0, };

	moved[gear] = 1;
	ndir[gear] = dir;

	if (gear == 1) {
		if (v1[2] != v2[6]) {
			moved[2] = 1;
			ndir[2] = -dir;
			if (v2[2] != v3[6]) {
				moved[3] = 1;
				ndir[3] = dir;
				if (v3[2] != v4[6]) {
					moved[4] = 1;
					ndir[4] = -dir;
				}
			}
		}
	}
	else if (gear == 4) {
		if (v4[6] != v3[2]) {
			moved[3] = 1;
			ndir[3] = -dir;
			if (v3[6] != v2[2]) {
				moved[2] = 1;
				ndir[2] = dir;
				if (v2[6] != v1[2]) {
					moved[1] = 1;
					ndir[1] = -dir;
				}
			}
		}
	}
	else if (gear == 2) {
		if (v2[6] != v1[2]) {
			moved[1] = 1;
			ndir[1] = -dir;
		}
		if (v2[2] != v3[6]) {
			moved[3] = 1;
			ndir[3] = -dir;
			if (v3[2] != v4[6]) {
				moved[4] = 1;
				ndir[4] = dir;
			}
		}
	}
	else if (gear == 3) {
		if (v3[2] != v4[6]) {
			moved[4] = 1;
			ndir[4] = -dir;
		}
		if (v2[2] != v3[6]) {
			moved[2] = 1;
			ndir[2] = -dir;
			if (v1[2] != v2[6]) {
				moved[1] = 1;
				ndir[1] = dir;
			}
		}
	}

	//마지막에 rotate시켜줌
	for (int i = 1; i <= 4; i++) {
		if (moved[i] == 1)
			rotate(i, ndir[i]);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char temp;
	for (int i = 0; i < 8; i++) {
		cin >> temp;
		v1.push_back(temp-'0');
	}
	for (int i = 0; i < 8; i++) {
		cin >> temp;
		v2.push_back(temp-'0');
	}
	for (int i = 0; i < 8; i++) {
		cin >> temp;
		v3.push_back(temp-'0');
	}
	for (int i = 0; i < 8; i++) {
		cin >> temp;
		v4.push_back(temp-'0');
	}

	int n;
	cin >> n;
	while (n--) {
		int gear, dir;
		cin >> gear >> dir;
		move(gear, dir);
	}
	
	cout << v1[0] + v2[0] * 2 + v3[0] * 4 + v4[0] * 8;

	return 0;
}