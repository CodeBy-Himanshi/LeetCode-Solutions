int duplicateNumbersXOR(int* nums, int numsSize) {
     int counts[51] = {0};
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
        if (counts[nums[i]] == 2)
            result ^= nums[i];
    }
    return result;
}