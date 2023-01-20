#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue <int> left;	//중앙값 기준 큰 거
	priority_queue <int, vector<int>, greater<int>> right; //중앙값 기준 작은 거
	
	int num;
	cin >> num;
	left.push(num);
	cout << num << "\n";
	
	int t_left;

	for (int i = 2; i <= n; i++) {
	
		cin >> num;

		if (i % 2 == 0) {
			t_left = left.top();

			if (num < t_left) {
				right.push(t_left);
				left.pop();
				left.push(num);
			}
			if (num >= t_left)
				right.push(num);
		}

		if (i % 2 == 1) {
			int t_right = right.top();

			if (num <= t_right)
				left.push(num);
			if (num > t_right) {
				left.push(t_right);
				right.pop();
				right.push(num);
			}
		}
		
		t_left = left.top();
		cout << t_left << "\n";
	}
}