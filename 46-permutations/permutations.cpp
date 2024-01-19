class Solution {
    vector<vector<int>> result{};
private:
    void backtracking(int i, vector<int> &nums) {
        if (i >= nums.size()) result.push_back(nums);
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            backtracking(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        backtracking(0, nums);
        return result;
    }
};