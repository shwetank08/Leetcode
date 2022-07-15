class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int i,int j,int &curr){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1){
            grid[i][j] = -1;
            curr+=1;
            dfs(grid,i+1,j,curr);
            dfs(grid,i,j+1,curr);
            dfs(grid,i-1,j,curr);
            dfs(grid,i,j-1,curr);
        }
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int curr = 0;
                    dfs(grid,i,j,curr);
                    mx = max(mx,curr);
                }
            }
        }
        return mx;
    }
};