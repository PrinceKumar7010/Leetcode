class Solution {
public:


    int longestSubarray(vector<int>& nums) {
     int count1=0;
        int count2=0;
        int sum=0;
        int check=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                check=1;
            }
        }
        if(check==0){
            return nums.size()-1;
        }
        for(int i=0;i<nums.size();i++){
            if(i==0 && nums[i]==0 || i==nums.size()-1 && nums[i]==0){
                continue;
            }
            if(count1+count2>sum){
                sum=count1+count2;
            }
            if(nums[i]==1){
                count2++;
            }
            else if (nums[i-1]==1 && nums[i+1]==1){
                count1=count2;
                count2=0;
            }
            else {
                count1=0;
                count2=0;
            }
            
        }
        if(count1+count2>sum){
                sum=count1+count2;
            }
        return sum;
    }
};