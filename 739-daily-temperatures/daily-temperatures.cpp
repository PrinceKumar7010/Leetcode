class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int,int>> s;
        vector<int> ans(n,0);
    
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && t[i] >= s.top().first) s.pop();
            if(!s.empty()) ans[i] = s.top().second-i;
            s.push({t[i],i});
        }
        return ans;
    }
};