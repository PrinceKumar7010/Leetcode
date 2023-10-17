class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
    int operations = 0;

    for (int num : nums) {
        if (counter[k - num] > 0) {
            operations++;
            counter[k - num]--;
        } else {
            counter[num]++;
        }
    }

    return operations;


    }
};