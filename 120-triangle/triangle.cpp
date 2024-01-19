class Solution {
public:
 

    int fxn( int i, int j, vector<vector<int>>&dp , vector<vector<int>>&a ){
        if( i == 0 and j == 0 )return a[0][0] ;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        int ans = INT_MAX ; 
        if(  j <= (i-1) )
         ans = min( ans , a[i][j] + fxn( i-1, j ,dp ,a ) ) ;
         if( (j-1) >= 0  )
         ans = min( ans , a[i][j] + fxn( i-1, j-1, dp , a )) ;
         dp[i][j] = ans ;
         return dp[i][j] ;
    }

    int minimumTotal(vector<vector<int>>& a) {
            int nr = a.size() ;
            vector<vector<int>>dp(nr,vector<int>(nr,-1)) ;
            int ans = INT_MAX ;
            for( int i = 0 ; i < nr ; i++ ){
                ans = min( ans , fxn(nr-1, i, dp, a )) ;
            }
            return ans ;
    }


};
