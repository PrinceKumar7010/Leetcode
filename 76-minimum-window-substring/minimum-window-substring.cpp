class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> ans{INT_MAX, -1}; // length, start index
        unordered_map<char, int> sMap, tMap;
        for (char & c : t) {
            tMap[c]++;
        }
        sMap = tMap;
        int have = 0, need = tMap.size();

        for (int l = 0, r = 0; r < s.length(); r++) {
            sMap[s[r]]--; 
            if (sMap[s[r]] == 0) {
                have++;
            }

            while (have == need) {
                if (r - l < ans.first) {
                    ans.first = r - l + 1;
                    ans.second = l;
                }
                sMap[s[l]]++;
                if (sMap[s[l]] == 1) {
                    have--;
                }
                l++;
            }

        }
        return ans.first == INT_MAX ? "" : s.substr(ans.second, ans.first);
    }
};