#include <iostream>
#include <string>

using namespace std;

class Trie {
public:
	Trie() : child() {}

	bool insert(string str) {
		Trie* cur = this;
		bool answer = true;

		for (char ch : str) {

			if (cur->finish == true)		//한 문자씩 지나가면서 finish가 없어야함
				answer = false;

			if (cur->child[ch - '0'] == nullptr)
				cur->child[ch - '0'] = new Trie();

			cur = cur->child[ch - '0'];
		}

		cur->finish = true;

		for (int i = 0; i < 10; i++) {		//끝났을 때 child가 없어야 함
			if (cur->child[i] != nullptr)
				answer = false;
		}

		return answer;
	}

private:
	Trie* child[10];
	bool finish = false;
};

Trie trie[51];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n;
	cin >> t;
	string callnumber;

	while (t--) {
		cin >> n;
		bool answer = true;

		while (n--) {

			bool test_answer = true;

			cin >> callnumber;
			test_answer = trie[t].insert(callnumber);
			if (test_answer == false) {		//틀릴 때 바로 break 해버리면 입력 다 안받고 넘어감
				answer = false;
			}
		}

		if (answer == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}