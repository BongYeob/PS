#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
  int answer = 0;
    
  queue<long int> q1;
	queue<long int> q2;
    
  int len = queue1.size();
    
  long int sum = 0;
	long int sum1 = 0, sum2 = 0;

  for(auto i : queue1){
      q1.push(i);
      sum1 += i;        
  }
  for(auto i : queue2){
      q2.push(i);
      sum2 += i;
  }
	sum = sum1 + sum2;
  
  if (sum % 2 == 1)
		return -1;
  
  long int target = sum / 2;
	int cnt = 0;
  long int temp;
	
	while (1) {

		if (sum1 < target) {
			temp = q2.front();
			q2.pop();
			q1.push(temp);
			sum1 += temp;
		}
		else if (sum1 > target) {
			temp = q1.front();
			q1.pop();
			q2.push(temp);
			sum1 -= temp;
		}
		else if (sum1 == target) {
			answer = cnt;
			break;
		}
		cnt++;

		if (cnt > (len - 1) * 3) {
			answer = -1;
			break;
		}
	}
	return answer;
}