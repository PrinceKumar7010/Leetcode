class Solution {
public: 
    int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    
    vector<bool> hashArray(n, false);
    for (int num : nums) {
        if (1 <= num && num <= n) {
            hashArray[num - 1] = true;
        }
    }

   
    for (int i = 0; i < n; ++i) {
        if (!hashArray[i]) {
            return i + 1;
        }
    }

   
    return n + 1;
}
};