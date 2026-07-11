bool canJump(int* nums, int numsSize) {
    int maxreach=0;
    for(int i=0;i<numsSize;i++){
        if(i>maxreach)
            return false;
        if(maxreach<(i+nums[i]))
            maxreach=(i+nums[i]);
    }
    return true;
}