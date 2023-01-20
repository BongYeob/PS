#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void f(int num) {	//level
	
	if (num == m) {
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
			v.push_back(i);
			f(num + 1);
			v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	f(0);
}