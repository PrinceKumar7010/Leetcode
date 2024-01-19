class Solution {
public:
    int robhouse(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int rob = nums[i] + robhouse(i+2,nums,dp);
        int notrob = robhouse(i+1,nums,dp);
        return dp[i] = max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return robhouse(0,nums,dp);
    }
};