void moveZeroes(int* nums, int numsSize){
    int zerocnt=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==0)
            zerocnt++;
        else
            nums[i-zerocnt] = nums[i];
    }
    for(int i=numsSize-zerocnt; i<numsSize; i++)
        nums[i]=0;
}