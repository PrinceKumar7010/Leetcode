class Solution {
public:
    int maxLength(vector<string>& arr) {
        int answer = 0;
        vector<int> dp ={0};

        for (auto& s : arr) {
            /* now check whether s has duplicate characters or not */
            int dup = 0;
            int i;
            for (i = 0; i < s.length(); ++i) {
                char ch = s.at(i);
                /* if we come here that means this bit was already set so
                 * duplicates are present */
                if (dup & (1 << (ch - 'a')))
                    break;
                dup |= (1 << (ch - 'a'));
            }

            /* it string s has duplicates then we don't want to go further */
            if (i != s.length())
                continue;

            /* Now there might have been some previous unique characters
             * subsequences before this string so we need to cover those as well
             */

            for (int i = dp.size() - 1; i >= 0; --i) {
                /* this subsequence has some common charaacters so don't
                 * consider this one */
                if (dp[i] & dup)
                    continue;

                answer = max(answer, __builtin_popcount(dp[i] | dup));
                dp.push_back(dp[i] | dup);
            }
        }
        return answer;
    }
};