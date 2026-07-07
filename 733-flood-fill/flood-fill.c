/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int o, int n) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[0])
        return;
    if (image[r][c] != o || image[r][c] == n)
        return;
    image[r][c] = n;
    dfs(image, imageSize, imageColSize, r - 1, c, o, n);
    dfs(image, imageSize, imageColSize, r + 1, c, o, n);
    dfs(image, imageSize, imageColSize, r, c - 1, o, n);
    dfs(image, imageSize, imageColSize, r, c + 1, o, n);
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldcolor = image[sr][sc];
    if (oldcolor != color)
        dfs(image, imageSize, imageColSize, sr, sc, oldcolor, color);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}