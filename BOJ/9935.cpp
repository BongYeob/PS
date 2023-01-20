#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string str;
    cin >> str;

    string bomb;
    cin >> bomb;

    stack<char> stack1;

    reverse(str.begin(), str.end());

    for (int i = 0; i < str.size(); i++) {
        
        stack1.push(str[i]);

        if (stack1.top() == bomb[0] && stack1.size() >= bomb.size()) {

            string temp;
            for (int j = 0; j < bomb.size(); j++) {
                temp = temp + stack1.top();
                stack1.pop();
            }
            if (temp != bomb) {
                for (int j = 0; j < bomb.size(); j++) {
                    stack1.push(temp[bomb.size() - j - 1]);
                }
            }
        }
    }

    if (stack1.empty())
        cout << "FRULA";
    else {
        while (!stack1.empty()) {
            cout << stack1.top();
            stack1.pop();
        }
    }
}