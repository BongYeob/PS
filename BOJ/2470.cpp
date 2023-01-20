#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	while (n--) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;
	int right = start;
	int left = end;

	long int sum = INF;
	long int temp;
	while (start < end) {

		temp = v[start] + v[end];

		if (sum > abs(temp)) {
			sum = abs(temp);
			left = start;
			right = end;
			if (!sum)
				break;
		}

		if (temp < 0)
			start++;
		else if (temp > 0)
			end--;
	}
	cout << v[left] << " " << v[right];
}