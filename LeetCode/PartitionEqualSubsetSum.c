bool canPartition(int* nums, int numsSize){
    int dp[200][20000] = {0,};
    int sum =0;
    for(int i=0; i<numsSize; i++)
        sum+=nums[i];
    if(sum % 2 == 1)
        return false;
    
    int target = sum /2;
    
    dp[0][0] = 1;
	dp[0][nums[0]] = 1;

	for (int i = 1; i < numsSize; i++) {
		for (int j = 0; j <= target; j++) {
			if (dp[i - 1][j] == 1) {
				dp[i][j] = 1;
				dp[i][j + nums[i]] = 1;
			}
		}
	}
    if(dp[numsSize-1][target] == 1)
        return true;
    return false;
}