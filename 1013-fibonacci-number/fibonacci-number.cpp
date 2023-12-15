class Solution {
public:

    int helperfib(int n, vector<int> &dp){
    if(n==0 || n==1)return n;
    else if(dp[n]!=-1)return dp[n];
    
    
    return dp[n]=helperfib(n-1,dp)+helperfib(n-2,dp);
    
    
    }
    int fib(int n) {
        vector <int> dp(n+1,-1);
        int ans=helperfib(n,dp);
        return ans;
    }
};