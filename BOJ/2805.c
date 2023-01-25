#include <stdio.h>

int num[1000000];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	long long min = 0;
	long long max = -1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (max < num[i])
			max = num[i];
	}

	long long result = 0;

	while (min <= max) {
		long long mid = (min + max) / 2;
		long long temp = 0;

		for (int i = 0; i < n; i++)
			if (num[i] > mid)
				temp += num[i] - mid;

		if (temp >= m) {
			if (result < mid)
				result = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;
	}

	printf("%d", result);

	return 0;
}