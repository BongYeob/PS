//july, 2024

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num;

int check_good(int idx){

    vector<int> cp = num;
    cp.erase(cp.begin()+idx);

    int target = num[idx];
    int start = 0;
    int end = cp.size()-1;
    
    while(start < end){
        if(cp[start] + cp[end] == target)
            return 1;
        
        if(cp[start] + cp[end] < target)
            start++;
        else
            end--;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, temp;
    int cnt =0;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    if(num.size() <= 2)
        cout<<cnt;
    else{
        for(int i=0; i<n; i++)
            cnt += check_good(i);
    }

    cout<<cnt;
    return 0;
}