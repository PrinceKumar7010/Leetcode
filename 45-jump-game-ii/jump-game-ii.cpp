class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=INT_MAX;
        }
        for(int i=0;i<n;i++)
        {
            int k=nums[i];
            for(int j=i+1;j<n && j<i+k+1; j++)
            {
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};