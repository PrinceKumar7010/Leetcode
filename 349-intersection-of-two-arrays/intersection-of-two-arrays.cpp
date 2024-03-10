class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         vector<int> v;
        set<int> s1;
        set<int> s2;
        unordered_map <int,int> mp;
        for( auto i : nums1)s1.insert(i);
        for( auto i : nums2)s2.insert(i);
       
        for(auto i : s1){
            mp[i]++;
        }
         for(auto i : s2){
            mp[i]++;
        }

        for(auto i : mp){
            if(i.second==2)v.push_back(i.first);
        }
        return v;

    }
};