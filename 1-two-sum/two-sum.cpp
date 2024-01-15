class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
       unordered_set<int> s;
       vector<int> v;
        
        int r=-1,z=-1;
       for(int i=0;i<nums.size();i++){
       if(s.count(t-nums[i])){
          z=i;
           v.push_back(i);
            r=t-nums[i];
       }
       s.insert(nums[i]);
       }
       for(int i=0;i<nums.size();i++){
           if(nums[i]==r && i!=z)v.push_back(i);
       }

       return v;

    }
};