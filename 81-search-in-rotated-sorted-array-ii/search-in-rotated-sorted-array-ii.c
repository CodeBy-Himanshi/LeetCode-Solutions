bool search(int* nums, int numsSize, int target) {
    int lb=0, ub=numsSize-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(nums[mid]==target)
            return true;
        if(nums[lb]==nums[mid] && nums[mid]==nums[ub]){
            lb++;
            ub--;
            continue;
        }
        if(nums[lb]<=nums[mid]){
            if(target>=nums[lb] && target<nums[mid])
                ub=mid-1;
            else
                lb=mid+1;
        }
        else{
            if(target>nums[mid] && target<=nums[ub])
                lb=mid+1;
            else
                ub=mid-1;
        }
    }
    return false;
}