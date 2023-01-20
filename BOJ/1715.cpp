#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    int n;
    cin >> n;

    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        pq.push(temp);
    }

    int result = 0;

    while(pq.size() != 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int temp = first + second;
        result += temp;
        pq.push(temp);
    }

    cout<< result;
}