class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                i=i+3;
            }
            else{
                return nums[i];
            }
        }
       return nums[n-1]; 
    }
};