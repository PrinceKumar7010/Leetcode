class Solution {
public:
     
    int func( int i , int j , vector<vector<int>>&grid , vector<vector<int>>&dp , int nr , int nc ){
        if( i == 0 and  j == 0 ) return 1 ;
        int ways = 0 ;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        
        if( (i-1 >= 0 and j >= 0) and grid[i-1][j] != 1 ){
              ways += func( i-1 , j , grid , dp , nr , nc ) ;
        }
        if( ( i >= 0 and  j-1 >= 0 ) and grid[i][j-1] != 1  ){
            ways += func( i , j-1 , grid, dp , nr , nc ) ;
        }
         return dp[i][j] = ways ;

    }

    int uniquePathsWithObstacles(vector<vector<int>>&grid ) {
         int nr = grid.size() ;
         int nc = grid[0].size() ;
         if( grid[nr-1][nc-1] == 1 ) return  0 ;
         vector<vector<int>>dp( nr , vector<int>(nc,-1)) ;
         return func( nr-1 , nc-1 , grid , dp , nr , nc ) ;

    }
};