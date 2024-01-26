class Solution {
public:
    int dp[51][51][51];
    int solver(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)return 1;
        if(maxMove == 0)return 0;
        if(dp[startRow][startColumn][maxMove] !=-1)return dp[startRow][startColumn][maxMove];
        long long ans=0;
        ans+=solver(m,n,maxMove-1,startRow+1,startColumn);
        ans+=solver(m,n,maxMove-1,startRow,startColumn+1);
        ans+=solver(m,n,maxMove-1,startRow-1,startColumn);
        ans+=solver(m,n,maxMove-1,startRow,startColumn-1);
        return dp[startRow][startColumn][maxMove]=ans%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solver(m,n,maxMove,  startRow,  startColumn)%1000000007;
    }
};