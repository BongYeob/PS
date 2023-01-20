int maxSubArray(int* nums, int numsSize){
    int dp[100000];
    
    dp[0] = nums[0];
    
    for(int i=1; i<numsSize; i++){
        if(dp[i-1] >= 0)
            dp[i] = nums[i] + dp[i-1];
        else
            dp[i] = nums[i];
    }
    
    int max = dp[0];
    for(int i=1; i<numsSize; i++)
        if(max < dp[i])
            max = dp[i];
    
    return max;
}