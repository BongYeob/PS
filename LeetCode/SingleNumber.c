int singleNumber(int* nums, int numsSize){
    int check[60001] = {0,};
    int temp;
    for(int i=0; i<numsSize; i++){
        temp = nums[i];
        if(temp <0){
            temp = -temp + 30000;
        }
        check[temp]++;
    }
    for(int i=0; i<numsSize; i++){
        temp = nums[i];
        if(temp <0){
            temp = -temp + 30000;
        }
        if(check[temp]==1)
            return nums[i];
    }
    return 0;
}