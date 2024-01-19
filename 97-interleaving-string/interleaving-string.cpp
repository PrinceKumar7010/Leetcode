class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l = s1.size(), m = s2.size(), n = s3.size();
        if(l + m != n) return false;
        if (l == 0) return s2 == s3;
        if (m == 0) return s1 == s3;
        vector<vector<bool>> dp(l+1, vector<bool>(m+1, false));

        dp[l][m] = true;
        for(int i = 0; i < l; i++) {
            if(s1.substr(i, l-i) == s3.substr(m+i, l-i))
                dp[i][m] = true;
        }
        for(int j = 0; j < m; j++) {
            if(s2.substr(j, m-j) == s3.substr(l+j, m-j))
                dp[l][j] = true;
        }

        for(int i = l-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(s1[i] == s3[i+j] && s2[j] == s3[i+j]) {
                    if(dp[i+1][j] == true || dp[i][j+1] == true) dp[i][j] = true;
                }
                else if(s1[i] == s3[i+j]) {
                    if(dp[i+1][j] == true) dp[i][j] = true;
                }
                else if(s2[j] == s3[i+j]) {
                    if(dp[i][j+1] == true) dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};