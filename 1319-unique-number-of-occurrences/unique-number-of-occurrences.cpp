class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> v;
        set<int> s;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
         for(auto x:mp){
             v.push_back(x.second);
             s.insert(x.second);

         }
         if(v.size()==s.size())return true;
         return false;


    }
};