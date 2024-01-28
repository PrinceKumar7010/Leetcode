class Solution {
public:
    int totalFruit(vector<int>& fs) {
        unordered_map<int, int> mp;
        int i = 0;
        int mx = 0, len = 0;
        for (int j = 0; j < fs.size(); j++) {
            mp[fs[j]]++;
            if (mp.size() <= 2)
                mx = max(j - i + 1, mx);
            if (mp.size() > 2) {
                while (mp.size() > 2) {
                    if (mp[fs[i]] > 1)
                        mp[fs[i++]]--;
                    else
                        mp.erase(fs[i++]);
                }
                mx = max(j - i + 1, mx);
            }
        }
        return mx;
    }
};