#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, b, c;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	cin >> b >> c;

	long long result = 0;
	result += n;

	for (auto i : a) {
		int temp = i - b;
		if (temp > 0) {
			if (temp % c == 0)
				result += temp / c;
			else
				result += temp / c + 1;
		}
	}

	cout << result;

	return 0;
}