class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string t = "";
        for(char &a: path) {
            if (a == '/') {
                if (t == "..") {
                    if (!st.empty()) st.pop();
                }
                else if (t != "" && t != ".") st.push(t);
                t = "";
            }
            else t += a;
        }
        if (t == "..") {
            if (!st.empty()) st.pop();
        }
        else if (t != "" && t != ".") st.push(t);
        string ans = "";
        vector<string> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            ans += ("/" + v[i]);
        }
        return ans != "" ? ans : "/";
    }
};