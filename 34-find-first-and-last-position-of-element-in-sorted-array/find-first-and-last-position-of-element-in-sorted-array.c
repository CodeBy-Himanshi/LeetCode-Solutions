/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    result[0]=-1;
    result[1]=-1;
    int lb=0,ub=numsSize-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(nums[mid]==target){
            result[0]=mid;
            ub=mid-1;
        }
        else if(nums[mid]<target)
            lb=mid+1;
        else
            ub=mid-1;
    }
    lb=0,ub=numsSize-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(nums[mid]==target){
            result[1]=mid;
            lb=mid+1;
        }
        else if(nums[mid]<target)
            lb=mid+1;
        else
            ub=mid-1;
    }
    return result;
}