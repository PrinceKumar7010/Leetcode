class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int s=0,y=0;
    for(int i=0;i<nums.size();i++){
    int t=target-nums[i];
    
    if(mp.count(t)>0){
        return {i,mp[t]};
    }
    else{
        mp[nums[i]]=i;
    }
}

return {};
    }
};