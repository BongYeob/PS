#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num;

	vector<int> v;

	v.push_back(0);
	while (n--) {
		
		cin >> num;
		if (num > v.back()) {
			v.push_back(num);
		}
		else {
			int iter = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[iter] = num;
		}
	}
	cout << v.size() - 1;
}