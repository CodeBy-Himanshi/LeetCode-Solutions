/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* ans = (int*)malloc(matrixSize * sizeof(int));
    *returnSize = matrixSize;
    for (int i = 0; i < matrixSize; i++) {
        int degree = 0;
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 1)
                degree++;
        }
        ans[i] = degree;
    }
    return ans;
}
