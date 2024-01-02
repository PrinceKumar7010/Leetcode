class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v;
        int n = t.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }

            if (st.empty()) {
                v.push_back(0);  // No warmer day found
            } else {
                v.push_back(st.top() - i);  // Calculate the distance to the warmer day
            }

            st.push(i);
        }

        reverse(v.begin(), v.end());  // Reverse the result to have it in the correct order
        return v;
    }
};