int findDuplicate(int* nums, int numsSize) {
    int* counts = (int*)calloc(numsSize, sizeof(int));
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
        if (counts[nums[i]] == 2) {
            result = nums[i];
            break;
        }
    }
    free(counts);
    return result;
}