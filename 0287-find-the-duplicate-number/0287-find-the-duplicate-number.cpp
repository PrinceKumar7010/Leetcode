class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int,int> mp;
        int res;
        for(int i=0;i<nums.size();i++){

            mp[nums[i]]++;
        }
        for(auto i:mp){

            if(i.second>=2)res=i.first;
        }
        return res;
    }
};