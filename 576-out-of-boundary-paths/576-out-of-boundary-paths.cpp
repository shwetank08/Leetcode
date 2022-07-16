class Solution {
public:
    long long mod = 1e9+7;
    long long dfs(int m, int n, int M, int r, int c,vector<vector<vector<int>>>&dp){
        if(M<0){
            return 0;
        }
        if(r==m || c==n ||r<0 ||c<0){
            return 1;
        }
        if(dp[M][r][c]!=-1){
            return dp[M][r][c];
        }
        long down = dfs(m,n,M-1,r+1,c,dp);
        long top = dfs(m,n,M-1,r-1,c,dp);
        long right = dfs(m,n,M-1,r,c+1,dp);
        long left = dfs(m,n,M-1,r,c-1,dp);
        
        long sum = 0;
        sum = ((left+right+top+down)%mod)%mod;
        dp[M][r][c]=sum;
        return sum;
        
    }
    
    int findPaths(int m, int n, int M, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(M+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        dp[M][m][n] = dfs(m,n,M,startRow,startColumn,dp);
        return dp[M][m][n];
    }
};