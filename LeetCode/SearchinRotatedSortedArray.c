int search(int* nums, int numsSize, int target){
    
    
    int left = 0;
    int right = numsSize-1;
    while(left <= right){
        int mid = (left + right)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] >= nums[left]){ //왼쪽이 정렬되어 있음
            if(target >= nums[left] && target <= nums[mid])
                right = mid -1;
            else
                left = mid + 1;
        }
        else{   //오른쪽이 정렬되어 있음
            if(target >= nums[mid] && target <= nums[right])
                left = mid +1;
            else
                right = mid -1;
        }
    }
    
    return -1;
}