#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int num[10001];
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int start = 0, end = 0;
	int cnt = 0;

	int sum = num[start];

	while (end != n) {
		if (sum == m) {
			cnt++;
			sum -= num[start];
			start++;
			end++;
			sum += num[end];
		}
		else if (sum > m && start < end) {
			sum -= num[start];
			start++;
		}
		else if (sum > m && start == end) {
			end++;
			start++;
			sum = num[start];
		}
		else if (sum < m) {
			end++;
			sum += num[end];
		}
	}

	cout << cnt;
}