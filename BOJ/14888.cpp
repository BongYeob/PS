#include <iostream>

using namespace std;

int n;
int num[11];
int opernum[4] = { 0, };
int oper[11];
int max1;
int min1;

void dfs(int level) {
	if (level == n - 1) {
		int temp = num[0];
		for (int i = 0; i < n - 1; i++) {
			if (oper[i] == 0)
				temp += num[i + 1];
			else if (oper[i] == 1)
				temp -= num[i + 1];
			else if (oper[i] == 2)
				temp *= num[i + 1];
			else
				temp /= num[i + 1];
		}

		if (min1 > temp)	min1 = temp;
		else if (max1 < temp)	max1 = temp;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opernum[i] == 0)
			continue;

		opernum[i]--;
		oper[level] = i;
		dfs(level + 1);
		opernum[i]++;
	}
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cin >> opernum[0] >> opernum[1] >> opernum[2] >> opernum[3];

    int cnt = 1;
	max1 = num[0];
	for (int i = 0; i < opernum[0]; i++)
		max1 += num[cnt++];
	for (int i = 0; i < opernum[1]; i++)
		max1 -= num[cnt++];
	for (int i = 0; i < opernum[2]; i++)
		max1 *= num[cnt++];
	for (int i = 0; i < opernum[3]; i++)
		max1 /= num[cnt++];
	min1 = max1;

	dfs(0);
	
	cout << max1 << "\n" << min1;

	return 0;
}