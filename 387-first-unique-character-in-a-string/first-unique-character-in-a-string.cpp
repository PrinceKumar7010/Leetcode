class Solution {
public:
    int firstUniqChar(string s) {
       int x=0;
        unordered_map <char,int> mp;
        for(int i=0;i<s.length();i++){
        if(mp.find(s[i])!=mp.end()){
            if (mp[s[i]] != -1) {
        mp[s[i]] = -1;
    }
        }    
        else{
            mp[s[i]]=i;
        }    
            
        }
        int mn=INT_MAX;
        for(auto i :mp){
            if(i.second>=0){
                x++;
            mn=min(mn,i.second);
        }
            
        }
        if(x==0)return -1;
        return mn;
        
         
    }
};