int climbStairs(int n){
    int dp[46] ={0,};
    dp[0] = 1;
    dp[1] = 1;
    
    if(n==1)
        return 1;
    
    int temp = 2;
    while(temp <= n){
        dp[temp] = dp[temp-1] + dp[temp-2];
        temp ++;
    }
    return dp[n];
}