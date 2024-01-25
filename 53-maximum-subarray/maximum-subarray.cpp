class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            mx = max(sum, mx);
            if (sum < 0) {
                sum = 0;
            }
        
       
        }
        return mx;
    }
};