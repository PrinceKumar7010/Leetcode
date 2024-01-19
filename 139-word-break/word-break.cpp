class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // Initialize Lookup Map
        unordered_map<string, bool> dictLookup;

        for (string word : wordDict) {
            dictLookup[word] = true;
        }

        int n = s.size();

        // Initialize our dp
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Define variables outside to save space
        int j = 0;
        string curr = "";

        for (int i = 0; i < n; i++) {
            /*  curr is the current substring
                i is the starting position 
                j is the starting position */
            j = i;
            while (j > -1) {
                // If the substring before the current substring was verify current current substring is in the wordDict or not.
                if (dp[j]) {
                    curr = s.substr(j, i - j + 1);
                    if (dictLookup[curr]) {
                        dp[i + 1] = true;
                        break;
                    }
                }
                j--;
            }
        }
        return dp[n];
    }
};