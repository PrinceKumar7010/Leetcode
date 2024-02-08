class Solution {
public:

    int ln(vector<int>& nums,vector<vector<int>> &dp,int ind,int pre,int n)
{
    if(ind==n){
        return 0;
    }
    if(dp[ind][pre+1]!=-1){
        return dp[ind][pre+1];
    }
    int ntake=0+ln(nums,dp,ind+1,pre,n);
int take=0;
if(pre==-1 || nums[pre]<nums[ind]){
take=1+ln(nums,dp,ind+1,ind,n);
}
    
    
   return dp[ind][pre+1]=max(take,ntake);

}
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
       int ind=0;
       
        return ln(nums,dp,ind,ind-1,n);
    }
};