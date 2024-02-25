class Solution {
public:

   int path(int m,int n,int i,int j,vector<vector<int>>& dp){
       if(i==m-1 && j==n-1)return 1;
       if(i>m-1 || j>n-1)return 0;
       if(dp[i][j]){
           return dp[i][j];
       }
       int rtake=path(m,n,i+1,j,dp);
       int ttake=path(m,n,i,j+1,dp);
       return dp[i][j]=rtake+ttake;


   } 

   
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));


        return path(m,n,0,0,dp);
    }
};