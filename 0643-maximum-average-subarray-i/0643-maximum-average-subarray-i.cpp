class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        long long sum = 0; // Change the type of sum to long long
        int n = nums.size();
        
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        ans = double(sum) / k;
        
        for(int i = 0; i < n - k; i++) {
            sum += nums[i + k] - nums[i];
            ans = max(ans, double(sum) / k);
        }
        
        return ans;
    }
};
