#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for(int i=0; i<tangerine.size(); i++){
        if(m[tangerine[i]])
            m[tangerine[i]]++;
        else
            m[tangerine[i]] = 1;
    }
    
    priority_queue<int> pq;
    for(auto i : m)
        pq.push(i.second);
    
    while(1){
        if(k <= 0){
            return answer;
            break;
        }
        
        k -= pq.top();
        pq.pop();
        answer++;
    }
    
    return answer;
}