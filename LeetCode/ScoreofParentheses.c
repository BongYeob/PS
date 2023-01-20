int scoreOfParentheses(char * s){
    int top=-1;
    int stack[100]={0,};
    int size = strlen(s);
    for(int i=0; i<size; i++){
        if(s[i] == '(')
            stack[++top] = -1;
        else{
            int temp =0;
            if(stack[top] == -1){
                stack[top] = 1;
            }
            else{
                while(stack[top] != -1){
                    temp+=stack[top];
                    top--;
                }
                stack[top] = temp * 2;
            }
        }
    }
    int result =0;
    for(int i=0; i<=top; i++)
        result += stack[i];
    return result;
}