class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> v;
      map<int,int>mp;
      int sm=0;
      for(int i=0;i<nums.size();i++)mp[nums[i]]++;
      for(auto i:mp)v.push_back(i.second);
      for(int i=0;i<v.size();i++){
          if(v[i]==1)return -1;
        sm+=v[i]/3;
       if(v[i]%3)sm++;
       } 
      return sm;
       
    }
};