class Solution {
public:
    void gs(string output, int n, int open, int close, int i,
            vector<string>& v) {
        if (i == 2 * n) {
            v.push_back(output);
            return;
        }
        
        if (open < n) {
            gs(output + '(', n, open + 1, close, i + 1, v);
        }
        if (close < open) {
            gs(output + ')', n, open, close + 1, i + 1, v);
        }
    }

    vector<string> generateParenthesis(int n) {
        string output = "";
        vector<string> v;
        gs(output, n, 0, 0, 0, v);
        for (auto i : v)
            cout << i << " " << endl;
        return v;
    }
};
