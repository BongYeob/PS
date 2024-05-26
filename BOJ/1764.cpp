#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>> N>>M;

    map<string, int> m;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        m.insert({s, 0});
    }

    vector<string> name;
    for(int i=0; i<M; i++){
        string s;
        cin>>s;
        if(m.find(s) != m.end())
            name.push_back(s);
    }
    
    sort(name.begin(), name.end());
    cout<<name.size()<<"\n";
    for(auto i : name)
        cout<<i<<"\n";
}