// #include "potd.cpp"
class Solution
{
    bool isPalindrome(string &s)
    {
        int first = 0, last = s.size()-1;
        while (first <= last)
        {
            if (s[first] != s[last])
                return 0;

            first++, last--;
        }
        return 1;
    }
    void getPalindromes(int idx, string &s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(temp);
            return;
        }

        string temp_str = "";
        for (int i = idx; i < s.size(); i++)
        {
            temp_str += s[i];
            if (isPalindrome(temp_str))
            {
                temp.push_back(temp_str);
                getPalindromes(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        vector<vector<string>> ans;

        getPalindromes(0, s, temp, ans);

        return ans;
    }
};