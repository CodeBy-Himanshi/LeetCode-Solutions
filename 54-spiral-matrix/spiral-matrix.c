/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result=(int*)malloc(matrixSize*matrixColSize[0]*sizeof(int));
    *returnSize=0;
    int top=0, bottom=matrixSize-1, left=0, right=matrixColSize[0]-1;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++)
            result[(*returnSize)++]=matrix[top][j];
        top++;
        for(int i=top;i<=bottom;i++)
            result[(*returnSize)++]=matrix[i][right];
        right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--)
                result[(*returnSize)++]=matrix[bottom][j];
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                result[(*returnSize)++]=matrix[i][left];
            left++;
        }
    }
    return result;
}