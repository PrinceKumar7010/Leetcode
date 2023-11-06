class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map <string,vector<string>> mp;
       
       for(int i=0;i<strs.size();i++){
             vector<string> s;
             string a=strs[i];
             sort(strs[i].begin(),strs[i].end());
             mp[strs[i]].push_back(a);
             
       }
        vector<vector<string>> ans;
       for(auto i=mp.begin();i!=mp.end();++i){
          ans.push_back(i->second);

       }
      
      return ans;
      
      
      
      
      
      
      }
};