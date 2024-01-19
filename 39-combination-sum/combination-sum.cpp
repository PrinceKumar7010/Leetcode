class Solution {
public:
    void func(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if (idx == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            func(idx, target - arr[idx], arr, ans, ds);
            ds.pop_back();
        }
        func(idx + 1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, target, candidates, ans, ds);
        return ans;
    }
};