#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    map<int, int> m;    //끝나는 시각, cnt
    
    for(auto str : lines){
        stringstream stream(str);
        string time;
        string timing;
        
        stream>>time;
        stream>>time;
        stream>>timing;

        int finish = stoi(time.substr(0,2))*60*60*1000 + 
											stoi(time.substr(3,2))*60*1000 +
											stoi(time.substr(6,2))*1000 +
											stoi(time.substr(9,3)); 
											        
        int start = finish - stod(timing.substr(0, timing.size()-1)) * 1000 + 1;
        
        for(auto i : m){
            if(i.first >= start - 1000 + 1){   //1초
                m[i.first]++;
            }   
        }
        if(!m[finish]){
            m[finish] = 1;
        }
    }
    
    for(auto i : m){
        if(answer < i.second){
            answer = i.second;
        }
    }
    
    return answer;
}