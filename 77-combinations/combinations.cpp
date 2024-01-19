class Solution {
public:
    void util(vector<int>& arr, vector<int>& temp, vector<vector<int>>& res, int k, int i){
        if(i == arr.size()){
            if(temp.size() == k)
                res.push_back(temp);
            return;
        }
        util(arr, temp, res, k, i + 1);
        temp.push_back(arr[i]);
        util(arr, temp, res, k, i + 1);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        for(int i = 1; i<=n; ++i) arr.push_back(i);
        vector<int> temp;
        util(arr, temp, res, k, 0);
        return res;
    }
};