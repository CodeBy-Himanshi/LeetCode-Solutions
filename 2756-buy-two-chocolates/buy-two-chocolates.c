int compare(const void *a, const void *b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) 
        return -1;
    if (val1 > val2)
         return 1;
    return 0;
}
int buyChoco(int* prices, int pricesSize, int money) {
    qsort(prices, pricesSize, sizeof(int), compare);
    if(prices[0]+prices[1]<=money)
         return money-(prices[0]+prices[1]);
    return money;
}