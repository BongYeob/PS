int answer =0;
int check[13];
    
int f(int depth, int numsSize, int* nums) {
	if (depth == numsSize) {
		int result = 0;
		for (int i = 0; i < numsSize; i++) {
			if (check[i] == 1) {
				result ^= nums[i];
			}
		}
		answer += result;
		return 0;
	}
  check[depth] = 0;
	f(depth + 1, numsSize, nums);
	check[depth] = 1;
	f(depth + 1, numsSize, nums);
	return 0;
}

int subsetXORSum(int* nums, int numsSize){
    answer =0;
    for(int i=0; i<13; i++)
        check[i] =0;
    f(0, numsSize, nums);
    return answer;
}