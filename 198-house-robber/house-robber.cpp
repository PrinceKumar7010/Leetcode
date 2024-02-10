class Solution {
public:


   int hou(vector<int>& nums,int i, vector<int> &dp){
     if(i>=nums.size())return 0;
     if(dp[i]!=-1)return dp[i];
     return dp[i]=max(hou(nums,i+1,dp),hou(nums,i+2,dp)+nums[i]);
   }
   

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       return hou(nums,0,dp);
    }
};