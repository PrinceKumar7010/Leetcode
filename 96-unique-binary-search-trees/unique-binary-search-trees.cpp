#include <vector>

class Solution {
public:
    unsigned long long nCr(int n, int r) {
        if (r > n)
            return 0;

        std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(r + 1, 0));

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= std::min(i, r); ++j) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp[n][r];
    }

    int numTrees(int n) {
        return static_cast<int>(nCr(2 * n, n) / (n + 1));
    }
};

