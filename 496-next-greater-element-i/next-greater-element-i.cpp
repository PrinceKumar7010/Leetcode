class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n, -1);
        vector<int> result;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(nums2[i]);
        }
        n = nums1.size();

        for (int i = 0; i < n; i++) {
            int cur = nums1[i];
            for (int j = 0; j < nums2.size(); j++) {
                if (cur == nums2[j])
                    result.push_back(ans[j]);
            }
        }
        return result;
    }
};