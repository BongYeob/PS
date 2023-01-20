#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int cnt[26] = { 0, };
bool check[26] = { false, };		//이미했던 알파벳인가
int result[26] = { 0, };			//최종 숫자
bool alphabet_cnt[26] = { false, };
int numbers = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	vector<string> v;

	cin >> num;

	while (num--) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (auto i : v) {
		int size = i.size();

		for (int j = 0; j < size; j++) {
			cnt[i[j]-'A'] += pow(10, size - j -1);
			alphabet_cnt[i[j] - 'A'] = true;
		}
	}

	for (auto i : alphabet_cnt) {
		if (i == true)
			numbers++;
	}

	for (int i = 9; i > 9 - numbers; i--) {	//개수 조정
		int max = -1;
		int temp;

		for (int j = 0; j < 26; j++) {
			if (cnt[j] > max && check[j] == false) {
				max = cnt[j];
				temp = j;
			}
		}

		check[temp] = true;
		result[temp] = i;
	}

	int answer = 0;

	for (int i = 0; i < 26; i++) {
		answer += (cnt[i] * result[i]);
	}

	cout << answer;
}