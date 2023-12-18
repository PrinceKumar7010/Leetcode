class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>mp;
        int s=0,y=0;
    for(int i=0;i<nums.size();i++){
    int t=target-nums[i];
    
    if(mp.count(t)>0){
        
        
        v.push_back(i);
        v.push_back(mp[t]);
        break;
    }
    else{
        mp[nums[i]]=i;
    }
}

return v;
    }
};