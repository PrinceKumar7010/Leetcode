class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
   int n=nums.size();
    vector<int> res(n+1,0);
    for(int i=0;i<nums.size();i++){
       if (nums[i] > 0 && nums[i] <= n) { 
        res[nums[i]]++;
    }
    }
    
    for(int i=1;i<res.size();i++){
    if(res[i]==0)return i;
    }
    
     return res.size();
    }
};