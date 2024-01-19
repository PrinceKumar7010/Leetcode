class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //making 2d dp as row and col both are changing
        vector<vector<int>>dp(n,vector<int>(n));
        //filling ist row same as it is 
        for(int col =0;col<n;col++){
            dp[0][col] =matrix[0][col];
        }
        //now doing work from 2nd row
        for(int row=1;row<n;row++){
            for(int col =0;col<n;col++){
                int a = INT_MAX;// to find {row-1,col-1}element
                int b = INT_MAX; // to find {row-1,col+1}element
                if(col-1>=0){
                    a = dp[row-1][col-1];
                }
                 if(col+ 1<n){
                    b = dp[row-1][col+1];
                }
                dp[row][col] = matrix[row][col]+ min({dp[row-1][col],a,b});

            }
        }
        //findig minumum sum from the last row
        int result = INT_MAX;
        int lastrow = n-1;
        for(int col =0;col<n;col++){
            result = min(result,dp[lastrow][col]);
        }
        return result;
           
        
    }

};