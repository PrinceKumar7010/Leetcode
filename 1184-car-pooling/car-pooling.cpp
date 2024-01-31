class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int cap) {
      unordered_map <int,int> mp;
for(int j=0;j<t.size();j++){
      for(int i=t[j][1];i<t[j][2];i++){
          mp[i]+=t[j][0];
      }  
    }
    for (auto i:mp)if(i.second>cap)return false;
    return true;
    }
};