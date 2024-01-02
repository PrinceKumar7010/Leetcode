class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       vector<vector<int>> v1;
       map<int,int> mp;
       int n=nums.size();
       for(int j=0;j<n;j++) mp[nums[j]]++;
       int c=0,q=1;
       while(c<n){
            vector<int> v;
                for(auto t:mp){
                    if( (t.second) >0){
                        v.push_back(t.first);
                        mp[t.first]=t.second-1;
                        c++;
                    }
                }
        v1.push_back(v);
        for(auto c : v)cout<<c<<" ";
        cout<<endl;
    }
    
   return v1;
   } 
};