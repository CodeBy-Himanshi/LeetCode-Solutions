int compare(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) 
        return -1;
    if (arg1 > arg2)
         return 1;
    return 0;
}
int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int prod1 = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];
    int prod2 = nums[0] * nums[1] * nums[numsSize-1];
    return (prod1 > prod2) ? prod1 : prod2;
}