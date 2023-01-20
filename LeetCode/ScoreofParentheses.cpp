class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int size = s.size();
        for(int i=0; i<size; i++){
            if(s[i] == '(')
                stack.push(-1);
            else{
                int temp=0;
                if(stack.top()==-1){
                    stack.pop();
                    stack.push(1);
                }
                else{
                    while(1){
                        if(stack.top()==-1){
                            stack.pop();
                            stack.push(temp*2);
                            break;
                        }
                        else{
                            temp+=stack.top();
                            stack.pop();
                        }
                    }
                }
            }
        }
        
        int result = 0;
        while(!stack.empty()){
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};