int compare(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) 
        return -1;
    if (arg1 > arg2) 
        return 1;
    return 0;
}
void sortColors(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
}