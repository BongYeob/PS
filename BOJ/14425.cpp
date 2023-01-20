#include <iostream>
#include <map>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> str;
	string temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		str[temp] = 1;
	}
	
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (str[temp] == 1)
			cnt++;
	}
	cout << cnt;

}