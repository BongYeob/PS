#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	int dp[16] = { 0, };

	for (int i = n; i >= 1; i--) {
		if (i + v[i].first > n + 1)
			continue;
		else {
			dp[i] = v[i].second;
			int temp=0;
			for (int j = i + v[i].first; j <= n; j++) {
				if (temp < dp[j])
					temp = dp[j];
			}
			dp[i] += temp;
		}
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

	return 0;
}