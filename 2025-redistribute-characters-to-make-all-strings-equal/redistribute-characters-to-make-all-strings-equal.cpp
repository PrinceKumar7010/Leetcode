class Solution {
public:
    bool makeEqual(vector<string>& w) {
        int n=w.size();
        if(n==1 || n==0)return true;
      unordered_map<char,int> mp;
      for(int i=0;i<w.size();i++){
          string a=w[i];
          for(int j=0;j<a.length();j++){
               mp[a[j]]++;
          }
      }

      for(auto i: mp)if(i.second%n!=0)return false;

      return true;  
    }
};