#include <iostream>

using namespace std;

int n;
int s[20][20];

int arr[20] = { 0, };
int cnt = 0;
int min1 = 987654321;

void dfs(int level) {
	if (level == n) {
		if (cnt == n / 2) {

			int temp = 0;
			int temp1 = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j && arr[i] == 0 && arr[j] == 0)
						temp += s[i][j];
					else if (i != j && arr[i] == 1 && arr[j] == 1)
						temp1 += s[i][j];
				}
			}

			temp = abs(temp - temp1);
			if (min1 > temp)
				min1 = temp;
		}
		return;
	}

	arr[level] = 1;
	cnt++;
	dfs(level+1);
	cnt--;
	arr[level] = 0;
	dfs(level + 1);
	
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	dfs(0);
	cout << min1;

	return 0;
}