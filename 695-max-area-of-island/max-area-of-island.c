int dfs(int** grid, int gridSize, int* gridColSize,int i, int j){
    if(i<0 || i>=gridSize || j<0 || j>=gridColSize[0] || grid[i][j]==0)
        return 0;
    grid[i][j]=0;
    int area=1;
    area+=dfs(grid,gridSize,gridColSize,i-1,j);
    area+=dfs(grid,gridSize,gridColSize,i+1,j);
    area+=dfs(grid,gridSize,gridColSize,i,j-1);
    area+=dfs(grid,gridSize,gridColSize,i,j+1);
    return area;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    if(gridSize==0)
         return 0;
    int max=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]==1){
                int area=dfs(grid,gridSize,gridColSize,i,j);
                if(area>max)
                    max=area;
            }
        }
    }
    return max;
}