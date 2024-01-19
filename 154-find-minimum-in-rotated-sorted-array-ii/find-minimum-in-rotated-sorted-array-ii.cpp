class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(nums[mid] < nums[right]) // Right half sorted
            {
                mini = min(mini, nums[mid]);
                right = mid-1;
            }
            else if(nums[left] < nums[mid])
            {
                 mini = min(mini, nums[left]); // Left half sorted.
                 left = mid+1;
            }
            else
            {
                if(nums[left] == nums[mid])
                {
                    for(int i=left;i<=mid;i++)
                    {
                        mini = min(mini,nums[i]);
                    }
                    left = mid+1;
                }
                else 
                {
                    for(int i=mid;i<=right;i++)
                    {
                        mini = min(mini,nums[i]);
                    }
                    right = mid-1;
                }
            }
        }
        return mini;
    }
};