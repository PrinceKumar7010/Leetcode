class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
       for(int i=0;i<=nums.size();i++){
           if(i<nums.size())x=x^nums[i];
           x=x^i;
         
       } 
     return x;
    }
};