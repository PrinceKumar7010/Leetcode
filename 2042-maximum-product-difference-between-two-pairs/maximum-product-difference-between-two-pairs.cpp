class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0,b=0;
        a=nums[0]*nums[1];
        b=nums[nums.size()-1]*nums[nums.size()-2];
        return b-a;
    }
};