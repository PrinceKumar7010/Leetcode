class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v;
        unordered_set<int> s;
        int y = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i]) > 0) {
                y = nums[i];
            }
            s.insert(nums[i]);
        }
        int sum = 0;
        for (auto i : s) {
            sum += i;
        }
        int u = (n * (n + 1)) / 2;
        int r = u - sum;

        v.push_back(y);
        v.push_back(r);
        return v;
    }
};