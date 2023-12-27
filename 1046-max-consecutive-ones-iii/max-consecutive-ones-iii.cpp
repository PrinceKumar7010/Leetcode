class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int p1 = 0, p2 = 0;

        int cnt0 = 0, max_len = 0;

        while(p2 < nums.size()){
            if(nums[p2] == 0){
                cnt0++;
                if(cnt0 > k){
                    max_len = max(max_len,(p2-1)-p1+1);
                    while(nums[p1]!=0 and p1 < p2){
                        p1++;
                    }
                    p1++;
                    cnt0--;
                }
            }
            max_len = max(max_len,p2-p1+1);
            p2++;
        }
        max_len = max(max_len,(p2-1)-p1+1);
        return max_len;
    }
};