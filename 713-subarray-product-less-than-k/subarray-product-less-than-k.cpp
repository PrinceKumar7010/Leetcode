class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mx=0;
        int pr=1;
        int n=nums.size();
        int j=0;
        if(k<=1)return 0;
    for(int i=0;i<nums.size();i++){
        pr*=nums[i];
        while(j<n && pr>=k){
            pr/=nums[j];
            j++;
        }
        mx+=i-j+1;
        
        
    }
    
return mx;
    }
};