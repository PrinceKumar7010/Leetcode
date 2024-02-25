class Solution {
public:
    int count(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;
        if (i < 0)
            return 1e9;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int take = 1e9;
        if (amount >= coins[i]) {
            take = count(coins, amount - coins[i], i, dp) + 1;
        }
        int ntake = count(coins, amount, i - 1, dp);

        return dp[i][amount] = min(take, ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int u=count(coins, amount, n - 1, dp);
         if(u==1e9)return -1;
        return u;
    }
};