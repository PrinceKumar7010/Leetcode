class Solution {
public:
    
    int path(int i,int j,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
     if(i==m-1 && j==n-1)return grid[i][j];

     if(i>=m || j>=n)return 1e9;
     if(dp[i][j]!=-1)return dp[i][j];
     return dp[i][j]=min(path(i+1,j,m,n,dp,grid)+grid[i][j],path(i,j+1,m,n,dp,grid)+grid[i][j]);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int> (n+1,-1));
        return path(0,0,m,n,dp,grid);
    }
};