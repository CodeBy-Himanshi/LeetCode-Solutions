int dfs(int** grid,int gridSize,int* gridColSize,int i,int j){
    if(i<0||i>=gridSize||j<0||j>=gridColSize[0])
        return 0;
    if(grid[i][j]==1)
        return 1;
    grid[i][j]=1;
    int up=dfs(grid,gridSize,gridColSize,i-1,j);
    int down=dfs(grid,gridSize,gridColSize,i+1,j);
    int left=dfs(grid,gridSize,gridColSize,i,j-1);
    int right=dfs(grid,gridSize,gridColSize,i,j+1);
    if(up==1&&down==1&&left==1&&right==1)
        return 1;
    return 0;
}
int closedIsland(int** grid, int gridSize, int* gridColSize) {
    if(gridSize==0)
        return 0;
    int c=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]==0)
                if(dfs(grid,gridSize,gridColSize,i,j)==1)
                    c++;
        }
    }
    return c;
}