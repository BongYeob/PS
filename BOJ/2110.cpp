#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;
	int home[200001];

	for (int i = 0; i < n; i++)
		cin >> home[i];

	sort(home, home + n);

	int mingap = 1;
	int maxgap = home[n - 1] - home[0];
	int mid;
	
	int answer;
	while (mingap <= maxgap) {
		int start = 0;
		int finish = 1;
		int cnt = 1;

		mid = (mingap + maxgap) / 2;

		while (finish < n) {
			if (home[finish] - home[start] >= mid) {
				cnt++;
				start = finish;
				finish++;
			}
			else
				finish++;
		}
		if (cnt < c)
			maxgap = mid -1;
		else {
			answer = mid;
			mingap = mid + 1;
		}
	}
	cout << answer;
}