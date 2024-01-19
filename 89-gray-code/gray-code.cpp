class Solution {
public:
    vector<int> grayCode(int n) {
        int cnt = 1 << n;
        vector<int> ans;
        ans.reserve(cnt);
        for (int i = 0; i < cnt; i++) {
            ans.push_back(i ^ (i / 2));
        }
        return ans;
    }
};