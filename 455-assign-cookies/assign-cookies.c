int compare(const void *a, const void *b) {
    int val1 = *(const int*)a;
    int val2 = *(const int*)b;
    if (val1 < val2) 
        return -1;
    if (val1 > val2) 
        return 1;
    return 0;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    int cp = 0, cop = 0;
    while (cp < gSize && cop < sSize) {
        if (s[cop] >= g[cp])
            cp++;
        cop++;
    }
    return cp;
}