//july, 2024

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    vector<int> num;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        num.push_back(temp);
    }
    
    vector<int> dp;
    dp.push_back(num[0]);

    for(int i=1; i<n; i++){
        if(num[i] > dp.back())
            dp.push_back(num[i]);
        else{
            int idx = lower_bound(dp.begin(), dp.end(), num[i]) - dp.begin();
            dp[idx] = num[i];
        }
    }
    
    cout<<n - dp.size();
    return 0;
}