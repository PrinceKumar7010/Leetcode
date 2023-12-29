class Solution {
public:
    int maxProduct(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int i=nums.size()-1,j=nums.size()-2;
      return ((nums[i]-1)*(nums[j]-1));  
    }
};