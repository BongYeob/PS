#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[9] = { false, };
vector<int> v;

void f(int num) {	//level
	
	if (num == m) {
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			v.push_back(i);
			f(num + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	f(0);
}