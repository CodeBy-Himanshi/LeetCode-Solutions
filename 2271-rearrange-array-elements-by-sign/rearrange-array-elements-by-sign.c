/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int p = 0;
    int n = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[p] = nums[i];
            p += 2;
        } else {
            result[n] = nums[i];
            n += 2;
        }
    }
    return result;
}