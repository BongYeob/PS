#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

class trie {
public:
	trie() : child() {

	}
	void insert(string str) {
		trie* cur = this;
		for (char ch : str) {
			if (cur->child[ch - 'a'] == nullptr)
				cur->child[ch - 'a'] = new trie();
			cur = cur->child[ch - 'a'];
		}
		cur->finish = true;
	}

	void search(string str) {

		trie* cur = this;
		bool flag = true;

		for (char ch : str) {
			if (cur->child[ch - 'a'] == nullptr) {
				flag = false;
				break;
			}
			cur = cur->child[ch - 'a'];
		}

		if (cur->finish == false)
			flag = false;

		if (flag == true)
			cnt++;
	}

private:
	trie* child[26];
	bool finish = false;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	string str;
	trie trie1;
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		trie1.insert(str);
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		trie1.search(str);
	}
	cout << cnt;
}