#include <string>
#include <vector>

using namespace std;

int check(string str, int key){
    
    vector < pair<string, int> > temp;

	for (int i = 0; i < str.size() / key; i++)
		temp.push_back({ str.substr(i * key, key), 1 });
	if (str.size() % key != 0)
		temp.push_back({ str.substr(str.size() / key * key), 1 });
	
	for (int i = 0; i < temp.size() - 1; i++) {

		int next = i + 1;
		if (temp[i].first == temp[next].first) {
			temp[next].second = temp[i].second + 1;
			temp[i].second = -1;
		}
	}

	int answer = 0;
    
	for (auto i : temp) {
		if (i.second == -1)
			continue;
		else if (i.second == 1)
			answer += i.first.size();
		else {
			answer += i.first.size();
			answer += to_string(i.second).size();
		}
	}
    
    return answer;
}

int solution(string s) {
    int answer = 0;
    
    int min = s.size();
    for(int i=1; i<=s.size()/2; i++){
        int ta = check(s,i);
        if(min > ta )
            min = ta;
    }
    answer = min;
    return answer;
}