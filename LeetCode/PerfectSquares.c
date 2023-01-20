int numSquares(int n){
    int dp[10001];
    for(int i=0; i<10001; i++)
        dp[i] = 987654321;
    
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; i-j*j>=0; j++){
            if(dp[i] > dp[i-j*j]+1)
                dp[i] = dp[i-j*j]+1;
        }
    }
    return dp[n];
}