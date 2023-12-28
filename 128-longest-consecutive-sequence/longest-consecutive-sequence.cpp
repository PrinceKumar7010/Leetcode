class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // If the input vector is empty, return 0
        }
        sort(nums.begin(), nums.end());

        int maxLength = 1; // Initialize length of the longest consecutive subsequence
        int currentLength = 1; // Initialize the length of the current consecutive subsequence

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) { // Avoid processing duplicate numbers
                if (nums[i] == nums[i - 1] + 1) {
                    currentLength++; // Increment the length of the current consecutive subsequence
                } else if (nums[i] > nums[i - 1] + 1) {
                    maxLength = max(maxLength, currentLength); // Update the maximum length
                    currentLength = 1; // Reset the current length for the next potential consecutive subsequence
                }
            }
        }
        
        return max(maxLength, currentLength); // Return the maximum length found
    }
};
