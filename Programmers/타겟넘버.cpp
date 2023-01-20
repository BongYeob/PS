#include <string>
#include <vector>

using namespace std;

int cnt=0;

void f (vector<int> &numbers, int target, int sum, int idx, int pos){
    
    if(pos == 0)
        sum += numbers[idx++];
    else
        sum -= numbers[idx++];
    
    if(idx == numbers.size()){
        if(sum == target)
            cnt++;
    }
    else{
        f(numbers, target, sum, idx, 0);
        f(numbers, target, sum, idx, 1);
    }
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    f(numbers, target, 0, 0, 0);   //벡터, 타겟, sum, idx, + or -
    f(numbers, target, 0, 0, 1);
    
    answer = cnt;
    return answer;
}