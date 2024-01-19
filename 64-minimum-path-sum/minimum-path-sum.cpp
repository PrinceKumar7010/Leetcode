class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp (row,vector<int>(col,-1));
        dp[0][0] = grid[0][0];
        path(row-1,col-1,grid,dp);
        return dp[row-1][col-1];
    }
    int path(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = grid[i][j] + min(path(i-1,j,grid,dp),path(i,j-1,grid,dp));
        return dp[i][j];
    }
};