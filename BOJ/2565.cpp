#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end());

	vector<int> lis;
	lis.push_back(v[0].second);

	for (int i = 1; i < n; i++) {

		if (v[i].second > lis.back())
			lis.push_back(v[i].second);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
			lis[idx] = v[i].second;
		}
	}

	cout << n - lis.size();

	return 0;
}