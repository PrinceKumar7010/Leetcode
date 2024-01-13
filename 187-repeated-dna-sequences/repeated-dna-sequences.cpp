class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> v;
        unordered_map <string,int>mp;
        string h="";
        for(int i=0;i<10;i++){
        h+=s[i];
        }
        mp[h]++;
        for(int j=10;j<s.length();j++){
        h.erase(0, 1);
        h+=s[j];
        mp[h]++;

        }
        for(auto i:mp){
            if(i.second>=2)v.push_back(i.first);
        }
        // if(v.empty() && s.length()>10){
        // string r = s.substr(0, 10);

        // v.push_back(r);
        // }
        return v;

        
    }
};