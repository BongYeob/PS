int getvalue(char c){
    if(c=='I')
        return 1;
    if(c=='V')
        return 5;
    if(c=='X')
        return 10;
    if(c=='L')
        return 50;
    if(c=='C')
        return 100;
    if(c=='D')
        return 500;
    if(c=='M')
        return 1000;
    return 0;
}

int romanToInt(char * s){
    
    int result=0;
    
    for(int i=0; i<strlen(s)-1; i++){
        int cur, next;
        cur = getvalue(s[i]);
        next = getvalue(s[i+1]);
        if(cur < next)
            result -= cur;
        else
            result += cur;
        
    }
    result += getvalue(s[strlen(s)-1]);
    
    
    return result;
}