/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* result;
    int check[1001]={0,};
    int cnt=0;
    int size=0;
    
    for(int i=0; i<size; i++){
        result[i] = 0;
    }
    
    if(nums1Size > nums2Size){
        result = (int*)malloc(sizeof(int)*nums1Size);
        size = nums1Size;
        for(int i=0; i<nums1Size; i++){
            check[nums1[i]]++;
        }
        for(int i=0; i<nums2Size; i++){
            if(check[nums2[i]] != 0){
                result[cnt] = nums2[i];
                check[nums2[i]]--;
                cnt++;
            }
        }
    }
    else{
        result = (int*)malloc(sizeof(int)*nums2Size);
        size = nums2Size;
        for(int i=0; i<nums2Size; i++){
            check[nums2[i]]++;
        }
        for(int i=0; i<nums1Size; i++){
            if(check[nums1[i]] != 0){
                result[cnt] = nums1[i];
                check[nums1[i]]--;
                cnt++;
            }
        }
        
    }

    *returnSize = cnt;
    return result;
    
    
}