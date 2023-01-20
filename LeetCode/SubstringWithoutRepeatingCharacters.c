int lengthOfLongestSubstring(char * s){
    int start=0, finish=0;
    int check[128];
    int result=0;
    for(int i=0; i<128; i++)
        check[i] = 0;
    
    int length = strlen(s);
    if(length==0)
        return 0;
    
    while(finish < length){
        
        if(check[s[finish]] == 0){
            check[s[finish]] = 1;
            if(finish-start+1 > result)
                result = finish-start+1;
            finish++;
        }
        else{
            for(int i=start; i<finish; i++){
                if(s[i] == s[finish]){
                    start = i+1;
                    break;
                }
                else{
                    check[s[i]] = 0;
                }
            }
            finish++;
        }
    }
    return result;
}