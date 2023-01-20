#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue <int> pq;
    priority_queue <int, vector<int>, greater<int> >  pq_less;
    
    vector< pair<int, int> > check;
    
    for(auto i : operations){
        char oper = i[0];
        string temp = i.substr(2);
        int num = stoi(temp);
        bool flag = false;
        
        if(oper == 'I'){
            pq.push(num);
            pq_less.push(num);
            
            flag = false;
            
            for(auto j : check){
                if(j.first == num){
                    j.second++;
                    flag = true;
                }
            }
            
            if(flag == false){
                check.push_back({num, 1});
            }
            
        }
        
        if(oper == 'D'){    //빈 큐 일때 삭제 하라는 거 처리 해야함
            if(check.size() == 0)
                continue;
            
            if(num == 1){   //최댓값
                int topnum = pq.top();
                pq.pop();
                
                for(int j=0; j<check.size(); j++){
                    if(check[j].first == topnum){
                        if(check[j].second != 1)
                            check[j].second--;
                        if(check[j].second == 1)
                            check.erase( check.begin() + j);
                    }
                }
            }
                
            else{           //최솟값
                int topnum = pq_less.top();
                pq_less.pop();
                
                for(int j=0; j<check.size(); j++){
                    if(check[j].first == topnum){
                        if(check[j].second != 1)
                            check[j].second--;
                        if(check[j].second == 1)
                            check.erase( check.begin() + j);
                    }
                }
            }
        }
        
    }
    
    if(check.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        int toppq = pq.top();
        answer.push_back(toppq);
        
        int toppqless = pq_less.top();
        answer.push_back(toppqless);
    }

    return answer;
}