class Solution {
public:

    int ts(int sum,int target,vector<int>& nums,int i){
if(sum==target && i==nums.size())return 1;
if(i>=nums.size())return 0;

return ts(sum+nums[i],target,nums,i+1)+ts(sum-nums[i],target,nums,i+1);
    }
    
    



int findTargetSumWays(vector<int>& nums, int target) {
    int j=0;


return ts(0,target,nums,j);;
    }
};