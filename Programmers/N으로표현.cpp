#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int makenum(int N, int level) { //5 55 555...
	int temp = 0;
	for (int i = 0; i < level; i++)
		temp += N * pow(10, i);
	return temp;
}

int solution(int N, int number) {
  int answer = 0;
  vector<int> dp[9];

	for (int i = 1; i <= 8; i++) {			//level
		dp[i].push_back(makenum(N, i));
		for (int j = 1; j <= i / 2; j++) {	// #combination
			
			for (auto first_num : dp[j]) {
				for (auto second_num : dp[i - j]) {
					
					dp[i].push_back(first_num + second_num);
					dp[i].push_back(first_num * second_num);
					if (first_num - second_num != 0)
						dp[i].push_back(abs(first_num - second_num));
					if (first_num >= second_num)
						dp[i].push_back(first_num / second_num);
					if (first_num < second_num)
						dp[i].push_back(second_num / first_num);
				}
			}
		}

		for (auto j : dp[i])
			if (j == number) {
				return i;
			}
	}
    answer = -1;
    return answer;
}