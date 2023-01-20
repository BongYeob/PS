#include <string>
#include <vector>
#include <sstream> 
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> info[100000];
    map<string, string> m;  //user_id, name
    
    for(int i=0; i<record.size(); i++){
        istringstream ss(record[i]);
        while(getline(ss, record[i], ' '))
            info[i].push_back(record[i]);
    }
    
    for(int i=0; i<record.size(); i++){
        
        string cmd = info[i][0];
        string id = info[i][1];
        
        if(cmd == "Enter"){
            
            string name = info[i][2];
            
            auto item = m.find(id);
            if(item!=m.end()){  //이미 있던 회원
                item->second = name;
            }
            else{   //새로운 회원
                m.insert({id, name});
            }
        }
        else if(cmd == "Change"){
            string name = info[i][2];
            m[id] = name;
        }
    }
    
    for(int i=0; i<record.size(); i++){
        string cmd = info[i][0];
        string id = info[i][1];
        string temp = "";
        if(cmd == "Enter"){
            temp = temp + m[id] + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if(cmd == "Leave"){
            temp = temp + m[id] + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    
    return answer;
}