class Solution {
public:
 vector<int> dp; int ml = -1; 
    int numSquares(int n) {
        if(n == 0) return 0; 
        if(ml == -1){
            vector<int> temp(n+1, -1); 
            dp = temp; ml++; 
        }

        int temp = 1; int count = INT_MAX; 
        while(temp* temp <= n){
            if(dp[n - temp*temp] == -1) dp[n - temp*temp] = numSquares(n - temp*temp) ; 
            int t = dp[ n - temp*temp]; 
            if(count > t + 1) count = t+1; temp++; 
        }

        if(count == INT_MAX) return 0 ;
        return count; 
    }
};