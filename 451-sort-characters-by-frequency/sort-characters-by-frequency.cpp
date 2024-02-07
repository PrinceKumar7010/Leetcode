class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map <char,int> mp;
        
        vector<pair<char,int>> v;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto i : mp){
           v.push_back(make_pair(i.first,i.second));
        }
          std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;  });
        reverse(v.begin(), v.end());
        string g="";
        for(auto i : v){
            while(i.second>0){
                g+=i.first;
                i.second--;
                }
            // cout<<i.first<<" "<<i.second<<endl;
        }

return g;
    }
};