class Solution {
public:
    void helper(int i, string s, string digits, map<char, vector<char>>& directory, vector<string>& solution){
        if(i == digits.size()){
            solution.push_back(s);
        }

        for(int j=0; j<directory[digits[i]].size(); j++)
            helper(i+1, s+directory[digits[i]][j], digits, directory, solution);
    }
    vector<string> letterCombinations(string digits) {
        map<char, vector<char>> directory = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };

        if(digits.size() == 0)
            return {};

        vector<string> solution;
        helper(0, "", digits, directory, solution);
        return solution;
    }
};