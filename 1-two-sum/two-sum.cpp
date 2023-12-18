class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>mp;
        int s=0,y=0;
    for(int i=0;i<nums.size();i++){
    int t=target-nums[i];
    
    if(mp.count(t)>0){
        s=t;
        y=i;
       
        break;
    }
    else{
        mp[nums[i]]=i;
    }
}
for(auto i:mp){
    if(i.first==s){
        v.push_back(i.second);
        v.push_back(y);
}
}
return v;
    }
};