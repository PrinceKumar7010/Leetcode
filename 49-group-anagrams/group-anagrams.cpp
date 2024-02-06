class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>res;
        vector<pair<string,string>>temp;

        for(auto it:strs){
            string s = it;
            sort(s.begin(),s.end());
            temp.push_back({s,it});
        }

        sort(temp.begin(),temp.end(),[&](pair<string,string>a,pair<string,string>b){
            return a.first<b.first;
        });
        
        int n = temp.size();
        int i = 0;

        while(i<n){
            
            vector<string>ans;
            while(i + 1 < n && temp[i].first==temp[i+1].first){
                ans.push_back(temp[i].second);
                i++;
            }
            ans.push_back(temp[i].second);
            res.push_back(ans);
            i++;
        }

        return res;
    }
};