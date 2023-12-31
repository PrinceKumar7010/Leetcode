class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        // array to store the first index of the 26 alphabetic characters
        std::vector<int> firstIndex(26, -1);
        // initialize a max variable with -1 to store the answer.
        int max = -1;

        for (int i = 0; i < s.length(); i++) {
            // extract the character at i in variable c.
            char c = s[i];
            // if c is not presented in substring (firstIndex[c - 'a'] == -1),
            // update its firstIndex[c - 'a'] = i.
            // else calculate the answer and update max = std::max(max, i - firstIndex[c - 'a'] - 1);
            if (firstIndex[c - 'a'] == -1)
                firstIndex[c - 'a'] = i;
            else
                max = std::max(max, i - firstIndex[c - 'a'] - 1);
        }

        // return max substring
        return max;
    }
};