int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize < 3)
        return numsSize;
    int result = 1;
    while (result <= numsSize)
        result <<= 1;
    return result;
}