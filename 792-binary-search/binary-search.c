int search(int* nums, int numsSize, int target) {
    int lb=0,ub=numsSize-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(target==nums[mid])
            return mid;
        else if(target<nums[mid])
            ub=mid-1;
        else
            lb=mid+1;
    }
    return -1;
}