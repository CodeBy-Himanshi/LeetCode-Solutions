int compare(const void *a, const void *b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) 
        return -1;
    if (val1 > val2)
         return 1;
    return 0;
}
int maxIceCream(int* costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), compare);
    int count = 0;
    for (int i = 0; i < costsSize; i++) {
        if (coins >= costs[i]){
            coins -= costs[i]; 
            count++;
        }
        else 
            break;
    }
    return count;
}