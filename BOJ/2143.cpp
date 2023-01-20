#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, t;
	cin >> t;
	cin >> n;

	vector<long long> a;
	vector<long long> b;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		a.push_back(temp);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		long long temp;
		cin >> temp;
		b.push_back(temp);
	}
	long long asum = 0, bsum = 0;
	long long cnt = 0;

	vector<long long> aa;
	vector<long long> bb;

	for (int i = 0; i < n; i++) {
		asum = 0;
		for (int j = i; j < n; j++) {
			asum += a[j];
			aa.push_back(asum);
		}
	}
	for (int i = 0; i < m; i++) {
		bsum = 0;
		for (int j = i; j < m; j++) {
			bsum += b[j];
			bb.push_back(bsum);
		}
	}

	sort(bb.begin(), bb.end());

	for (auto i : aa) {
		long long target = t - i;
		long lowidx = lower_bound(bb.begin(), bb.end(), target) - bb.begin();
		long highidx = upper_bound(bb.begin(), bb.end(), target) - bb.begin();
		cnt += (highidx - lowidx);
	}
	cout << cnt;
}